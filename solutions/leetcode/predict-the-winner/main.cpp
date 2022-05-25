class Solution {
   public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n));
        for (int i = 0; i < n; ++i) dp[i][i] = {nums[i], 0};

        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                int j = i + k - 1;
                array<int, 2> arr0 = {dp[i + 1][j][1] + nums[i],
                                      dp[i + 1][j][0]};
                array<int, 2> arr1 = {dp[i][j - 1][1] + nums[j],
                                      dp[i][j - 1][0]};
                if (arr0[0] == arr1[0] && arr0[1] > arr1[1])
                    swap(arr0, arr1);
                else if (arr0[0] < arr1[0])
                    swap(arr0, arr1);
                dp[i][j] = arr0;
            }
        }

        return dp[0][n - 1][0] >= dp[0][n - 1][1];
    }
};

class Solution {
   public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) dp[i][i] = nums[i];

        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                int j = i + k - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};

class Solution {
   public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) dp[i] = nums[i];

        for (int k = 1; k < n; ++k) {
            vector<int> new_dp(n);
            for (int i = 0; i + k < n; ++i) {
                new_dp[i] = max(nums[i] - dp[i + 1], nums[i + k] - dp[i]);
            }
            dp = move(new_dp);
        }

        return dp[0] >= 0;
    }
};
