class TicTacToe {
    vector<array<int, 2>> horizontal;
    vector<array<int, 2>> vertical;
    array<int, 2> diagonal0 = {0, 0};
    array<int, 2> diagonal1 = {0, 0};
    int target;

   public:
    TicTacToe(int n) : horizontal(n, {0, 0}), vertical(n, {0, 0}), target(n) {}

    int move(int row, int col, int player) {
        int p = player - 1;
        if (++horizontal[row][p] == target) return player;
        if (++vertical[col][p] == target) return player;
        if (row == col && ++diagonal0[p] == target) return player;
        if (row + col + 1 == target && ++diagonal1[p] == target) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
