class Solution {
   public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = nums.back() - nums.front();
        for (int i = 0; i < n - 1; ++i) {
            int high = max(nums[n - 1] - k, nums[i] + k);
            int low = min(nums[0] + k, nums[i + 1] - k);
            result = min(result, high - low);
        }
        return result;
    }
};
