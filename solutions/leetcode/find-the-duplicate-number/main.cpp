class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (i + 1 != nums[i]) {
                int j = nums[i] - 1;
                if (nums[i] == nums[j]) return nums[i];
                swap(nums[i], nums[j]);
            }
        }
        return 0;
    }
};

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};
