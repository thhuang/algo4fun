class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int result = nums[0];
        while (l <= r) {
            int m = l + (r - l) / 2;
            result = min(result, nums[m]);
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m - 1;
            } else {
                --r;
            }
        }
        return result;
    }
};
