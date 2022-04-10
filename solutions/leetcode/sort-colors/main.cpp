class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int p = 0;
        while (p <= r) {
            if (nums[p] == 0) {
                swap(nums[l], nums[p]);
                ++l, ++p;
            } else if (nums[p] == 1) {
                ++p;
            } else {
                swap(nums[r], nums[p]);
                --r;
            }
        }
    }
};
