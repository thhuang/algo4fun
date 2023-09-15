class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (0 <= nums[i] && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 1; i < n; ++i) {
            if (i != nums[i]) return i;
        }

        return nums.size();
    }
};
