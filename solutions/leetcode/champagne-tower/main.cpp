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

class Solution {
   public:
    double champagneTower(int poured, int query_row, int query_glass) {
        array<array<double, 101>, 102> glasses = {};
        glasses[0][0] = poured;
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 101; ++j) {
                double v = max(0.0, glasses[i][j] - 1);
                glasses[i + 1][j] += v / 2;
                glasses[i + 1][j + 1] += v / 2;
            }
        }
        return min(1.0, glasses[query_row][query_glass]);
    }
};
