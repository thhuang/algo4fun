class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < amount; ++i) {
            if (dp[i] == -1) continue;
            for (int c : coins) {
                if (i > amount - c) continue;
                if (dp[i + c] == -1)
                    dp[i + c] = dp[i] + 1;
                else
                    dp[i + c] = min(dp[i + c], dp[i] + 1);
            }
        }
        return dp.back();
    }
};

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (i < c) continue;
                if (dp[i - c] == -1) continue;
                if (dp[i] == -1) {
                    dp[i] = dp[i - c] + 1;
                } else {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return dp.back();
    }
};

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < dp.size(); ++i) {
            for (int c : coins) {
                if (i - c < 0) continue;
                if (dp[i - c] > amount) continue;
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp.back() > amount ? -1 : dp.back();
    }
};
