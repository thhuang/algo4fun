
#pragma once

#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <vector>

#include "fmt_print.h"
#include "generic_test_handler.h"
#include "json.h"
#include "platform.h"
#include "test_config.h"
#include "test_timer.h"
#include "test_utils.h"

namespace test_framework {
using json = nlohmann::json;

template <typename Function, typename Comparator>
TestResult RunTests(GenericTestHandler<Function, Comparator>& handler,
                    const TestConfig& config);

/**
 * The main test starter.
 */
template <typename Function, typename Comparator>
int GenericTestMain(
    const std::vector<std::string>& commandline_args,
    const std::string& test_data_file, Function test_func,
    Comparator comparator, const std::vector<std::string>& param_names,
    const std::function<void(TestConfig&)>& program_config = {}) {
    // Enables automatic flushing of the output stream after any output
    // operation.
    std::cout.setf(std::ios::unitbuf);

    try {
        TestConfig config = TestConfig::FromCommandLine(
            test_data_file, std::chrono::seconds{0}, 1, commandline_args);

        if (program_config) {
            program_config(config);
        }

        platform::SetOutputOpts(config.tty_mode, config.color_mode);

        GenericTestHandler<Function, Comparator> test_handler(
            test_func, comparator, param_names);
        return static_cast<int>(RunTests(test_handler, config));
    } catch (std::runtime_error& e) {
        std::cerr << "\nCritical error: " << e.what() << std::endl;
        return static_cast<int>(TestResult::RUNTIME_ERROR);
    }
}

template <typename Function, typename Comparator>
TestResult RunTests(GenericTestHandler<Function, Comparator>& handler,
                    const TestConfig& config) {
    std::vector<std::vector<std::string>> test_data =
        SplitTsvFile(config.test_data_dir + config.test_data_file);
    handler.ParseSignature(test_data[0]);

    auto metric_names = config.metric_names_override(handler.MetricNames());

    int test_nr = 0;
    int tests_passed = 0;
    const int total_tests = static_cast<int>(test_data.size() - 1);
    std::vector<std::vector<int>> metrics;
    std::vector<std::chrono::microseconds> durations;
    TestResult result = TestResult::FAILED;

    for (auto test_case : std::vector<std::vector<std::string>>{
             test_data.begin() + 1, test_data.end()}) {
        test_nr++;

        // Since the last field of test_data is test_explanation, which is not
        // used for running test, we extract that here.
        const std::string test_explanation = std::move(test_case.back());
        test_case.pop_back();

        TestOutput test_output;
        TestFailure test_failure;

        try {
            test_output = handler.RunTest(config.timeout_seconds,
                                          config.metrics_override, test_case);
            result = TestResult::PASSED;
            ++tests_passed;
            metrics.emplace_back(test_output.metrics);
            durations.emplace_back(test_output.timer.GetMicroseconds());
        } catch (TestFailure& e) {
            result = TestResult::FAILED;
            test_failure = e;
        } catch (TimeoutException& e) {
            result = TestResult::TIMEOUT;
            test_output.timer = e.GetTimer();
        } catch (std::runtime_error&) {
            throw;
        } catch (std::exception& e) {
            result = TestResult::UNKNOWN_EXCEPTION;
            test_failure = TestFailure(typeid(e).name())
                               .WithProperty(PropertyName::EXCEPTION_MESSAGE,
                                             std::string(e.what()));
        } catch (...) {
            result = TestResult::UNKNOWN_EXCEPTION;
            test_failure = TestFailure("Can't get exception information");
        }

        PrintTestInfo(result, test_nr, total_tests,
                      test_failure.GetDescription(), test_output.timer);

        if (result != TestResult::PASSED) {
            if (!handler.ExpectedIsVoid()) {
                test_case.pop_back();
            }
            if (test_explanation != "TODO" && !test_explanation.empty()) {
                test_failure.WithProperty(PropertyName::EXPLANATION,
                                          test_explanation);
            }
            PrintFailedTest(handler.ParamNames(), test_case, test_failure);

            const int tests_not_passed = test_nr - tests_passed;
            if (tests_not_passed >= config.num_failed_tests_before_stop) {
                break;
            }
        }
    }

    std::cout << std::endl;
    if (!durations.empty()) {
        std::string complexity;
        if (!metric_names.empty() && !metrics.empty() &&
            config.analyze_complexity) {
            std::vector<long long> time;
            std::transform(
                durations.begin(), durations.end(), std::back_inserter(time),
                [](const auto& d) {
                    return std::chrono::duration_cast<std::chrono::nanoseconds>(
                               d)
                        .count();
                });
            ShowComplexityNotification();
        }

        PrintPostRunStats(tests_passed, total_tests, complexity, durations);
    }
    return result;
}
}  // namespace test_framework
using test_framework::GenericTestMain;
