#include <epi/generic_test.h>

#include <vector>
using namespace std;

void RotateMatrix(vector<vector<int>>* square_matrix_ptr) {
    auto& square_matrix = *square_matrix_ptr;
    int mat_size = square_matrix.size();

    for (int i = 0; i < mat_size; ++i) {
        for (int j = 0; j < mat_size / 2; ++j) {
            swap(square_matrix[i][j], square_matrix[i][mat_size - 1 - j]);
        }
    }

    for (int i = 0; i < mat_size; ++i) {
        for (int j = 0; j < i; ++j) {
            // i = 2, j = 1, mat_size = 4
            // (2, 2) -> (1, 1)
            // i = 1, j = 0, mat_size = 4
            // (1, 3) -> (0, 2)
            swap(square_matrix[i][mat_size - 1 - j],
                 square_matrix[j][mat_size - 1 - i]);
        }
    }
}

vector<vector<int>> RotateMatrixWrapper(vector<vector<int>> square_matrix) {
    RotateMatrix(&square_matrix);
    return square_matrix;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"square_matrix"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &RotateMatrixWrapper,
                           DefaultComparator{}, param_names);
}
