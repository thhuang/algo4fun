class Solution {
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int seen = numeric_limits<int>::max();

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        int x = 0, y = 0, d = 0;
        vector<int> result(m * n);
        for (int i = 0; i < result.size(); ++i) {
            result[i] = matrix[x][y];
            matrix[x][y] = seen;

            auto [dx, dy] = directions[d];
            int xx = x + dx, yy = y + dy;
            if (xx < 0 || xx >= m || yy < 0 || yy >= n ||
                matrix[xx][yy] == seen) {
                d = (d + 1) % 4;
                tie(dx, dy) = directions[d];
                xx = x + dx, yy = y + dy;
            }

            x = xx, y = yy;
        }

        return result;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<int> result(m * n);
        for (int k = 0, i = 0, j = 0, d = 0; k < m * n; ++k) {
            result[k] = matrix[i][j];
            matrix[i][j] += 1000;

            int ii = i + directions[d][0];
            int jj = j + directions[d][1];

            if (ii < 0 || m <= ii || jj < 0 || n <= jj ||
                matrix[ii][jj] > 100) {
                d = (d + 1) % 4;
                ii = i + directions[d][0];
                jj = j + directions[d][1];
            }

            i = ii;
            j = jj;
        }

        return result;
    }
};
