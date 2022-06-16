class Solution {
    vector<array<int, 2>> directions = {{1, 2},  {2, 1},  {-1, -2}, {-2, -1},
                                        {1, -2}, {2, -1}, {-1, 2},  {-2, 1}};

   public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> prob(n, vector<double>(n, 1));
        while (k--) {
            vector<vector<double>> new_prob(n, vector<double>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    double c = 0;
                    for (auto [di, dj] : directions) {
                        int ii = i + di, jj = j + dj;
                        if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                        c += prob[ii][jj];
                    }
                    new_prob[i][j] = c / 8;
                }
            }
            prob = move(new_prob);
        }
        return prob[row][column];
    }
};
