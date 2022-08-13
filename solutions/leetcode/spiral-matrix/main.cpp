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
