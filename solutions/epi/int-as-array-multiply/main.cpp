#include <epi/generic_test.h>
using namespace std;

vector<int> Multiply(vector<int> num1, vector<int> num2) {
    int sign = num1[0] * num2[0] < 0 ? -1 : 1;
    num1[0] = abs(num1[0]);
    num2[0] = abs(num2[0]);

    vector<int> res(num1.size() + num2.size(), 0);

    for (int i = 0; i < num1.size(); ++i) {
        for (int j = 0; j < num2.size(); ++j) {
            int x = num1[num1.size() - 1 - i];
            int y = num2[num2.size() - 1 - j];
            res[i + j] += x * y;
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
        }
    }

    // reverse and remove the leading 0
    res = {
        find_if(res.rbegin(), res.rend(), [](int a) { return a != 0; }),
        res.rend(),
    };
    if (empty(res)) return {0};

    res[0] *= sign;
    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"num1", "num2"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &Multiply,
                           DefaultComparator{}, param_names);
}
