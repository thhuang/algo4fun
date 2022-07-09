class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n, -1e9);
        multiset<int> window;

        dp.front() = nums.front();
        window.emplace(dp.front());

        for (int i = 1; i < n; ++i) {
            dp[i] = *window.rbegin() + nums[i];
            window.emplace(dp[i]);
            if (window.size() > k) window.erase(window.find(dp[i - k]));
        }

        return dp.back();
    }
};
