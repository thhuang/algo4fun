class Solution {
   public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < size(nums) - 1; ++i) {
            if (nums[i] == nums[i - 1] && i - 2 >= 0) nums[i - 1] = nums[i - 2];
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) ++count;
            if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) ++count;
        }
        return count;
    }
};
