class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m] && (target < nums[l] || nums[m] < target)) {
                l = m + 1;
            } else if (nums[l] > nums[m] &&
                       (nums[m] < target && target < nums[l])) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (l == nums.size() || nums[l] != target) return -1;
        return l;
    }
};
