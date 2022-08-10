class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> cache(coins.size(), vector<int>(amount + 1, -1));

        function<int(int, int)> dfs = [&](int i, int k) -> int {
            if (k < 0) return 0;
            if (k == 0) return 1;
            if (cache[i][k] != -1) return cache[i][k];

            int s = 0;
            for (int j = i; j < coins.size(); ++j) {
                s += dfs(j, k - coins[j]);
            }

            return cache[i][k] = s;
        };

        return dfs(0, amount);
    }
};

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i - c < 0) continue;
                dp[i] += dp[i - c];
            }
        }
        return dp.back();
    }
};
