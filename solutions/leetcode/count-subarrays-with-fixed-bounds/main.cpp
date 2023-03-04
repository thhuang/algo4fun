class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        long long mn = -1, mx = -1, bound = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            if (v < minK || maxK < v) bound = i;
            if (v == minK) mn = i;
            if (v == maxK) mx = i;
            result += max(0LL, min(mn, mx) - bound);
        }
        return result;
    }
};
