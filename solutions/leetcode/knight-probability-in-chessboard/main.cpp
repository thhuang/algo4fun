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

class Solution {
    vector<array<int, 2>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

   public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> prob(
            n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) prob[i][j][0] = 1;

        function<double(int, int, int)> dfs = [&](int i, int j,
                                                  int mv) -> double {
            if (i < 0 || n <= i || j < 0 || n <= j) return 0;
            if (prob[i][j][mv] >= 0) return prob[i][j][mv];

            double result = 0;
            for (auto [di, dj] : directions)
                result += dfs(i + di, j + dj, mv - 1);

            return prob[i][j][mv] = result / directions.size();
        };

        return dfs(row, column, k);
    }
};
