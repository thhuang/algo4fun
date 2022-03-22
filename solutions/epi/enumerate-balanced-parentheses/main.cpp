#include <epi/generic_test.h>

#include <string>
#include <vector>
using namespace std;

vector<string> GenerateBalancedParentheses(int num_pairs) {
    vector<string> result;

    function<void(int, int, const string&)> generate =
        [&](int num_left, int num_right, const string& prefix) -> void {
        if (!num_right) {
            result.emplace_back(prefix);
            return;
        }

        if (num_left) {
            generate(num_left - 1, num_right, prefix + "(");
        }
        if (num_right > num_left) {
            generate(num_left, num_right - 1, prefix + ")");
        }
    };

    generate(num_pairs, num_pairs, "");

    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"num_pairs"};
    return GenericTestMain(args, "data.tsv", &GenerateBalancedParentheses,
                           UnorderedComparator{}, param_names);
}
