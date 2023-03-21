class Solution {
   public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        for (int l = 0; l <= n; ++l) {
            int r = l;
            while (r < n && nums[r] == 0) ++r;
            long long v = r - l;
            result += v * (v + 1) / 2;
            l = r;
        }
        return result;
    }
};
