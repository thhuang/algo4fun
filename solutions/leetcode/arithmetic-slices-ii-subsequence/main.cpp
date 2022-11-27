class Solution {
    using ll = long long;

   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        vector<unordered_map<ll, int>> dp(n);
        for (int r = 1; r < n; ++r) {
            for (int m = 0; m < r; ++m) {
                ll d = (ll)nums[r] - nums[m];
                int s = dp[m][d];
                dp[r][d] += s + 1;
                result += s;
            }
        }

        return result;
    }
};
