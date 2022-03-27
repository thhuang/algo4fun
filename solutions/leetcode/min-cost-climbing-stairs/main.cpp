class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = size(cost);
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        vector<int> dp = {0, cost[0]};
        for (int i = 1; i < size(cost); ++i) {
            dp = {dp[1], min(dp[0], dp[1]) + cost[i]};
        }
        return min(dp[0], dp[1]);
    }
};
