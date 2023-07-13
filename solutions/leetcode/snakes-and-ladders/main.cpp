class Solution {
    const int inf = numeric_limits<int>::max();

   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> flattenBoard = {-1};
        for (int i = board.size() - 1, r = 0; i >= 0; --i, ++r) {
            if (r & 1) {
                for (int j = board[i].size() - 1; j >= 0; --j) {
                    flattenBoard.push_back(board[i][j]);
                }
            } else {
                for (int j = 0; j < board[i].size(); ++j) {
                    flattenBoard.push_back(board[i][j]);
                }
            }
        }

        int result = 0;
        vector<int> steps(flattenBoard.size(), inf);
        queue<pair<int, int>> q;  // {idx, steps}
        q.push({1, 0});
        while (!q.empty()) {
            auto [i, v] = q.front();
            q.pop();

            if (steps[i] <= v) continue;
            steps[i] = v;

            if (i == flattenBoard.size() - 1) break;

            for (int d = 1; d <= 6 && i + d < flattenBoard.size(); ++d) {
                int jump = flattenBoard[i + d];
                if (jump != -1) {
                    q.push({jump, v + 1});
                } else {
                    q.push({i + d, v + 1});
                }
            }
        }

        if (steps.back() == inf) return -1;
        return steps.back();
    }
};

class Solution {
   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();
        int t = m * n;

        vector<array<int, 2>> indexToPosition(t + 1);
        for (int i = 0, k = 1; i < m; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; ++j)
                    indexToPosition[k++] = {m - 1 - i, j};
            } else {
                for (int j = n - 1; j >= 0; --j)
                    indexToPosition[k++] = {m - 1 - i, j};
            }
        }

        queue<pair<int, int>> q;
        q.push({1, 0});

        vector<bool> vis(t + 1, false);
        while (!q.empty()) {
            auto [i, mv] = q.front();
            q.pop();

            if (i == t) return mv;
            if (vis[i]) continue;
            vis[i] = true;

            for (int j = i + 1; j <= i + 6 && j <= t; ++j) {
                auto [x, y] = indexToPosition[j];
                if (int k = board[x][y]; k != -1) {
                    q.push({k, mv + 1});
                } else {
                    q.push({j, mv + 1});
                }
            }
        }

        return -1;
    }
};
