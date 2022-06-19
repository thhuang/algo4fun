class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int l = n; l >= 1; --l) {
            for (int r = l; r <= n; ++r) {
                for (int i = l; i <= r; ++i) {
                    dp[l][r] = max(dp[l][r],
                                   dp[l][i - 1] + dp[i + 1][r] + nums[l - 1] * nums[i] * nums[r + 1]);
                }
            }
        }

        return dp[1][n];
    }
};

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int d = 1; d <= n; ++d) {
            for (int l = 1; l + d - 1 <= n; ++l) {
                int r = l + d - 1;
                for (int m = l; m <= r; ++m) {
                    dp[l][r] = max(dp[l][r],
                                   dp[l][m - 1] + dp[m + 1][r] + nums[l - 1] * nums[m] * nums[r + 1]);
                }
            }
        }
        
        return dp[1][n];
    }
};
