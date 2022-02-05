#include <epi/fmt_print.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>
using namespace std;

void Rearrange(vector<int>* vec_ptr) {
    auto& vec = *vec_ptr;
    for (int i = 1; i < vec.size(); ++i) {
        if (i & 1 && vec[i - 1] > vec[i]) {
            swap(vec[i - 1], vec[i]);
        }
        if (!(i & 1) && vec[i - 1] < vec[i]) {
            swap(vec[i - 1], vec[i]);
        }
    }
    return;
}
void CheckAnswer(const vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
        if (i % 2) {
            if (A[i] < A[i - 1]) {
                throw TestFailure()
                    .WithProperty(PropertyName::RESULT, A)
                    .WithMismatchInfo(i, FmtStr("A[{}] <= A[{}]", i - 1, i),
                                      FmtStr("{} > {}", A[i - 1], A[i]));
            }
            if (i + 1 < A.size()) {
                if (A[i] < A[i + 1]) {
                    throw TestFailure()
                        .WithProperty(PropertyName::RESULT, A)
                        .WithMismatchInfo(i, FmtStr("A[{}] >= A[{}]", i, i + 1),
                                          FmtStr("{} < {}", A[i], A[i + 1]));
                }
            }
        } else {
            if (i > 0) {
                if (A[i - 1] < A[i]) {
                    throw TestFailure()
                        .WithProperty(PropertyName::RESULT, A)
                        .WithMismatchInfo(i, FmtStr("A[{}] >= A[{}]", i - 1, i),
                                          FmtStr("{} < {}", A[i - 1], A[i]));
                }
            }
            if (i + 1 < A.size()) {
                if (A[i + 1] < A[i]) {
                    throw TestFailure()
                        .WithProperty(PropertyName::RESULT, A)
                        .WithMismatchInfo(i, FmtStr("A[{}] <= A[{}]", i, i + 1),
                                          FmtStr("{} > {}", A[i], A[i + 1]));
                }
            }
        }
    }
}

void RearrangeWrapper(TimedExecutor& executor, vector<int> A) {
    executor.Run([&] { Rearrange(&A); });

    CheckAnswer(A);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "A"};
    return GenericTestMain(args, "data.tsv", &RearrangeWrapper,
                           DefaultComparator{}, param_names);
}
