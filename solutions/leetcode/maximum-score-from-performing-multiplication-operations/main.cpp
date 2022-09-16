class Solution {
   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        function<int(int, int)> dfs = [&](int i, int l) -> int {
            if (i == m) return 0;
            if (dp[i][l] != -1) return dp[i][l];

            int k = multipliers[i];
            return dp[i][l] = max(k * nums[l] + dfs(i + 1, l + 1),
                                  k * nums[n - i + l - 1] + dfs(i + 1, l));
        };

        return dfs(0, 0);
    }
};

class Solution {
   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int l = 0; l <= i; ++l) {
                int k = multipliers[i];
                dp[i][l] = max(k * nums[l] + dp[i + 1][l + 1],
                               k * nums[n - i + l - 1] + dp[i + 1][l]);
            }
        }

        return dp[0][0];
    }
};

class Solution {
   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();

        vector<int> dp(m + 1, 0);
        for (int i = m - 1; i >= 0; --i) {
            vector<int> new_dp(m + 1, 0);
            for (int l = 0; l <= i; ++l) {
                int k = multipliers[i];
                new_dp[l] = max(k * nums[l] + dp[l + 1],
                                k * nums[n - i + l - 1] + dp[l]);
            }
            dp = move(new_dp);
        }

        return dp[0];
    }
};
