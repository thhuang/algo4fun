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
