class Solution {
   public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int result = -1;
        sort(nums.begin(), nums.end());
        for (int l = 0, r = nums.size() - 1; l < r; ++l) {
            while (l < r && nums[l] + nums[r] >= k) --r;
            if (l == r) break;
            result = max(result, nums[l] + nums[r]);
        }
        return result;
    }
};
