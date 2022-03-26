class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = size(nums) - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
                continue;
            }
            if (nums[m] > target) {
                r = m - 1;
                continue;
            }
            return m;
        }
        return -1;
    }
};
