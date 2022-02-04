#include <epi/generic_test.h>

#include <array>
#include <unordered_map>
#include <vector>
using namespace std;

enum Direction { Right, Down, Left, Up };

vector<int> MatrixInSpiralOrder(const vector<vector<int>>& square_matrix) {
    unordered_map<Direction, Direction> next_direction{
        {Right, Down},
        {Down, Left},
        {Left, Up},
        {Up, Right},
    };
    unordered_map<Direction, array<int, 2>> direction_step{
        {Right, {0, 1}},
        {Down, {1, 0}},
        {Left, {0, -1}},
        {Up, {-1, 0}},
    };
    int mat_size = size(square_matrix);
    array<int, 2> row_range{0, mat_size - 1};
    array<int, 2> col_range{0, mat_size - 1};
    auto is_out_of_bound = [&row_range, &col_range](int i, int j) -> bool {
        return i < row_range[0] || i > row_range[1] || j < col_range[0] ||
               j > col_range[1];
    };
    auto update_boundary = [&row_range, &col_range](Direction new_direction) {
        switch (new_direction) {
            case Down:
                ++row_range[0];
                break;
            case Up:
                --row_range[1];
                break;
            case Right:
                ++col_range[0];
                break;
            case Left:
                --col_range[1];
                break;
        }
    };

    Direction dir = Right;
    array<int, 2> step = direction_step[dir];
    int i = 0, j = 0;
    vector<int> res;
    while (!is_out_of_bound(i, j)) {
        res.emplace_back(square_matrix[i][j]);

        if (is_out_of_bound(i + step[0], j + step[1])) {
            dir = next_direction[dir];
            update_boundary(dir);
            step = direction_step[dir];
        }

        i += step[0];
        j += step[1];
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"square_matrix"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &MatrixInSpiralOrder,
                           DefaultComparator{}, param_names);
}
