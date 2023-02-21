class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (m % 2 == 0) {
                if (nums[m - 1] == nums[m]) {
                    r = m - 2;
                } else if (nums[m] == nums[m + 1]) {
                    l = m + 2;
                } else {  // nums[m - 1] != nums[m] && nums[m] != nums[m + 1]
                    return nums[m];
                }
            } else {
                if (nums[m - 1] == nums[m]) {
                    l = m + 1;
                } else if (nums[m] == nums[m + 1]) {
                    r = m - 1;
                } else {  // nums[m - 1] != nums[m] && nums[m] != nums[m + 1]
                    return nums[m];
                }
            }
        }

        return nums[l];
    }
};
