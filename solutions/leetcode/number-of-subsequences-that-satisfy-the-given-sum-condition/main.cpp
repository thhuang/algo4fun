class Solution {
    const int mod = 1e9 + 7;

   public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) power[i] = power[i - 1] * 2 % mod;

        sort(nums.begin(), nums.end());

        long long result = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                --r;
            } else {
                (result += power[r - l]) %= mod;
                ++l;
            }
        }

        return result;
    }
};
