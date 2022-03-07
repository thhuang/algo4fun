#include <epi/generic_test.h>

#include <algorithm>
#include <vector>
using namespace std;

double FindSalaryCap(int target_payroll, vector<int> current_salaries) {
    sort(begin(current_salaries), end(current_salaries));

    int remain = target_payroll;
    for (int i = 0; i < size(current_salaries); ++i) {
        int val = current_salaries[i];
        if (val * (size(current_salaries) - i) > remain) {
            return (double)remain / (size(current_salaries) - i);
        }
        remain -= val;
    }

    return remain == 0 ? current_salaries.back() : -1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"target_payroll", "current_salaries"};
    return GenericTestMain(args, "data.tsv", &FindSalaryCap,
                           DefaultComparator{}, param_names);
}
