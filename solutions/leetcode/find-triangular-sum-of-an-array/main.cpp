class Solution {
   public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        return nums.front();
    }
};
