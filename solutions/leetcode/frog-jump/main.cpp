class Solution {
   public:
    bool canCross(vector<int>& stones) {
        int n = stones.back();

        unordered_map<int, unordered_set<int>> dp;
        for (int i : stones) dp[i];
        dp[0].insert(0);

        for (int i : stones) {
            for (int j : dp[i]) {
                for (int k = j - 1; k <= j + 1; ++k) {
                    if (k <= 0) continue;
                    if (i + k == n) return true;
                    if (i + k < n && dp.count(i + k)) dp[i + k].insert(k);
                }
            }
        }

        return false;
    }
};
