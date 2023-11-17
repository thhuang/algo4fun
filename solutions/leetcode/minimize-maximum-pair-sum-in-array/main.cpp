class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int l = 0, r = nums.size() - 1; l < r; ++l, --r) {
            result = max(result, nums[l] + nums[r]);
        }
        return result;
    }
};
