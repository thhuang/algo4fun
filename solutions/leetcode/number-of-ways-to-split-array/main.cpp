class Solution {
   public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        for (long long v : nums) total += v;

        long long count = 0;
        for (long long i = 0, s = 0; i < nums.size() - 1; ++i) {
            s += nums[i];
            if (s >= total - s) ++count;
        }

        return count;
    }
};
