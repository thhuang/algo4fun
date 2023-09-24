class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        array<array<double, 101>, 101> glasses = {};
        glasses[0][0] = poured;
        for (int i = 1; i < 101; ++i) {
            for (int j = 0; j < 101; ++j) {
                if (j > 0) glasses[i][j] += max(0.0, glasses[i - 1][j - 1] - 1) / 2;
                glasses[i][j] += max(0.0, glasses[i - 1][j] - 1) / 2;
            }
        }
        return min(1.0, glasses[query_row][query_glass]);
    }
};
