#include <epi/generic_test.h>
#include <epi/timed_executor.h>
using namespace std;

// Returns the number of valid entries after deletion.
int DeleteDuplicates(vector<int>* vec_ptr) {
    auto& vec = *vec_ptr;
    if (vec.size() == 0) return 0;

    int cnt = 1;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] == vec[cnt - 1]) continue;
        vec[cnt++] = vec[i];
    }

    return cnt;
}
vector<int> DeleteDuplicatesWrapper(TimedExecutor& executor, vector<int> A) {
    int end = executor.Run([&] { return DeleteDuplicates(&A); });
    A.resize(end);
    return A;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "A"};
    return GenericTestMain(args, "data.tsv", &DeleteDuplicatesWrapper,
                           DefaultComparator{}, param_names);
}
