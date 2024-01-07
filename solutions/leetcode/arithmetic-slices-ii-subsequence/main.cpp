class Solution {
    typedef long long ll;

   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<unordered_map<ll, int>> dp(n);
        for (int r = 1; r < n; ++r) {
            for (int l = 0; l < r; ++l) {
                auto d = (ll)nums[r] - nums[l];
                auto p = dp[l][d];
                result += p;
                dp[r][d] += p + 1;
            }
        }
        return result;
    }
};
