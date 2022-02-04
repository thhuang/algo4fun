#include <epi/generic_test.h>

#include <vector>
using namespace std;

vector<vector<int>> GeneratePascalTriangle(int num_rows) {
    vector<vector<int>> pascal_tri(num_rows);
    for (int i = 0; i < num_rows; ++i) {
        pascal_tri[i] = vector<int>(i + 1, 1);
    }

    // 1
    // 1 1
    // 1 2 1
    // 1 3 3 1
    // 1 4 6 4 1
    for (int i = 2; i < num_rows; ++i) {
        for (int j = 1; j < size(pascal_tri[i]) - 1; ++j) {
            pascal_tri[i][j] = pascal_tri[i - 1][j - 1] + pascal_tri[i - 1][j];
        }
    }

    return pascal_tri;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"num_rows"};
    return GenericTestMain(args, "main.cpp", "data.tsv",
                           &GeneratePascalTriangle, DefaultComparator{},
                           param_names);
}
