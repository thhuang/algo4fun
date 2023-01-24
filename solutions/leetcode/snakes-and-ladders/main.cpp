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
