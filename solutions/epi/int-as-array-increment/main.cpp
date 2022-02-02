#include <epi/generic_test.h>

#include <algorithm>
#include <vector>
using namespace std;

vector<int> PlusOne(vector<int> vec) {
    ++vec.back();
    for (int i = vec.size() - 1; i > 0 && vec[i] == 10; --i) {
        vec[i] = 0;
        ++vec[i - 1];
    }
    if (vec[0] == 10) {
        vec[0] = 1;
        vec.push_back(0);
    }
    return vec;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &PlusOne,
                           DefaultComparator{}, param_names);
}
