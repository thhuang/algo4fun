class Solution {
   public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp = {0, 0, 0};
        for (int i = 0; i < costs.size(); ++i) {
            dp = {min(dp[1], dp[2]) + costs[i][0],
                  min(dp[0], dp[2]) + costs[i][1],
                  min(dp[0], dp[1]) + costs[i][2]};
        }
        return *min_element(dp.begin(), dp.end());
    }
};

class Solution {
    const int m = 3;

   public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> dp(m, 0);
        for (int i = 0; i < n; ++i) {
            vector<int> new_dp(m, numeric_limits<int>::max());
            for (int prev = 0; prev < m; ++prev) {
                for (int curr = 0; curr < m; ++curr) {
                    if (prev == curr) continue;
                    new_dp[curr] = min(new_dp[curr], dp[prev] + costs[i][curr]);
                }
            }
            dp = move(new_dp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
