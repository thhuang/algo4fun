class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums.front();
        int end_sum = nums.front();
        for (int i = 1; i < size(nums); ++i) {
            end_sum = max(nums[i], end_sum + nums[i]);
            max_sum = max(max_sum, end_sum);
        }
        return max_sum;
    }
};
