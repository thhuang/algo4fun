class Solution {
    typedef long long ll;

   public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<ll>> dp(m + 1,
                              vector<ll>(n + 1, numeric_limits<int>::min()));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                array<ll, 5> candidates = {
                    dp[i][j], dp[i + 1][j], dp[i][j + 1], nums1[i] * nums2[j],
                    dp[i + 1][j + 1] + nums1[i] * nums2[j]};
                dp[i][j] = *max_element(candidates.begin(), candidates.end());
            }
        }

        return dp[0][0];
    }
};
