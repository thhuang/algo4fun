class Solution {
   public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n);

        map<int, int> mp;
        ++mp[0];

        for (int r = 0, l = r - k; r < n; ++l, ++r) {
            dp[r] = nums[r] + mp.rbegin()->first;
            ++mp[dp[r]];

            if (l < 0) continue;

            if (--mp[dp[l]] == 0) {
                mp.erase(dp[l]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
