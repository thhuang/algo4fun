class Solution {
    bool crush(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();

        bool modified = false;
        for (int i = 2; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (abs(board[i][j]) == abs(board[i - 1][j]) &&
                    abs(board[i][j]) == abs(board[i - 2][j])) {
                    board[i][j] = board[i - 1][j] = board[i - 2][j] =
                        -abs(board[i][j]);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 2; j < n; ++j) {
                if (abs(board[i][j]) == abs(board[i][j - 1]) &&
                    abs(board[i][j]) == abs(board[i][j - 2])) {
                    board[i][j] = board[i][j - 1] = board[i][j - 2] =
                        -abs(board[i][j]);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] < 0) {
                    board[i][j] = 0;
                    modified = true;
                }
            }
        }

        return modified;
    }

    void drop(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();

        for (int j = 0; j < n; ++j) {
            for (int i = m - 1, p = m - 1; i >= 0; --i) {
                if (board[i][j] > 0) {
                    swap(board[i][j], board[p--][j]);
                }
            }
        }
    }

   public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (crush(board)) drop(board);
        return board;
    }
};
