class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board.front().size();

        vector<vector<int>> prefix_sum(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            int row_sum = 0;
            for (int j = 0; j < m; ++j) {
                row_sum += board[i][j];
                if (i > 0) prefix_sum[i][j] += prefix_sum[i - 1][j];
                prefix_sum[i][j] += row_sum;
            }
        }

        auto calculate_population = [&](int i, int j) -> int {
            int r0 = max(0, i - 1);
            int c0 = max(0, j - 1);
            int r1 = min(n - 1, i + 1);
            int c1 = min(m - 1, j + 1);

            int sum = prefix_sum[r1][c1] - board[i][j];
            if (r0 > 0) sum -= prefix_sum[r0 - 1][c1];
            if (c0 > 0) sum -= prefix_sum[r1][c0 - 1];
            if (r0 > 0 && c0 > 0) sum += prefix_sum[r0 - 1][c0 - 1];

            return sum;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v = calculate_population(i, j);
                if (board[i][j] == 1 && (v == 2 || v == 3)) {
                    board[i][j] = 1;
                } else if (board[i][j] == 0 && v == 3) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
    const vector<array<int, 2>> directions = {
        {1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
    const int live = 1 << 1;

   public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (auto [di, dj] : directions) {
                    if (i + di < 0 || m <= i + di || j + dj < 0 || n <= j + dj)
                        continue;
                    cnt += board[i + di][j + dj] & 1;
                }

                int& v = board[i][j];
                if (v & 1) {
                    if (cnt == 2 || cnt == 3) v |= live;
                } else if (cnt == 3) {
                    v |= live;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = (board[i][j] & live) ? 1 : 0;
            }
        }
    }
};

class Solution {
    const vector<array<int, 2>> directions = {
        {1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
    const int live = 1 << 1;

   public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (auto [di, dj] : directions) {
                    if (i + di < 0 || m <= i + di || j + dj < 0 || n <= j + dj)
                        continue;
                    cnt += board[i + di][j + dj] & 1;
                }

                int& v = board[i][j];
                if (cnt == 3 || (v & 1 && cnt == 2)) v |= live;
            }
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = (board[i][j] & live) ? 1 : 0;
    }
};
