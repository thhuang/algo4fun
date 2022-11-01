class Solution {
   public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.front().size();

        vector<int> balls(n);
        iota(balls.begin(), balls.end(), 0);

        for (int i = 0; i < grid.size(); ++i) {
            vector<int> new_balls(n, -1);
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (j == n - 1) continue;
                    if (grid[i][j + 1] == -1) continue;
                    new_balls[j + 1] = balls[j];
                } else {  // grid[i][j] == -1
                    if (j == 0) continue;
                    if (grid[i][j - 1] == 1) continue;
                    new_balls[j - 1] = balls[j];
                }
            }
            balls = move(new_balls);
        }

        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            if (balls[i] != -1) result[balls[i]] = i;
        }

        return result;
    }
};
