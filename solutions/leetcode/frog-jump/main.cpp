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

class Solution {
   public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(n, false));
        dp[0][0] = true;

        for (int r = 1; r < n; ++r) {
            for (int l = 0; l < r; ++l) {
                int k = stones[r] - stones[l];
                if (k >= n) continue;
                if (dp[l][k - 1] || dp[l][k]) dp[r][k] = true;
                if (k + 1 < n && dp[l][k + 1]) dp[r][k] = true;
            }
        }

        for (auto b : dp.back()) {
            if (b) return true;
        }
        return false;
    }
};
