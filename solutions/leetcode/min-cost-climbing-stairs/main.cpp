class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        array<int, 2> dp = {0, 0};
        for (int i = 2; i <= cost.size(); ++i) {
            dp = {dp[1], min(dp[0] + cost[i - 2], dp[1] + cost[i - 1])};
        }
        return dp.back();
    }
};

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        array<int, 2> dp = {cost[0], cost[1]};
        for (int i = 2; i < cost.size(); ++i) {
            dp = {dp[1], min(dp[0], dp[1]) + cost[i]};
        }
        return min(dp[0], dp[1]);
    }
};

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        array<int, 2> dp = {0, 0};
        for (int v : cost) {
            dp = {dp[1], min(dp[0], dp[1]) + v};
        }
        return min(dp[0], dp[1]);
    }
};
