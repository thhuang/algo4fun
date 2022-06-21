class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int v : stones) sum += v;

        int n = stones.size();
        int k = sum / 2;
        vector<int> dp(k + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int v = stones[i - 1];
            for (int j = k; j >= v; --j) {
                dp[j] = max(dp[j], dp[j - v] + v);
            }
        }

        return sum - 2 * dp.back();
    }
};
