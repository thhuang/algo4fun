class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int result = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    result = max(result, dp[i][j] = dp[i - 1][j - 1] + 1);
            }
        }

        return result;
    }
};

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        vector<int> dp(n + 1, 0);

        int result = 0;
        for (int i = 1; i <= m; ++i) {
            vector<int> new_dp(n + 1, 0);
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    result = max(result, new_dp[j] = dp[j - 1] + 1);
            }
            dp = move(new_dp);
        }

        return result;
    }
};
