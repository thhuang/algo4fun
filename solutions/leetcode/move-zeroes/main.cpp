class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        for (int l = 0, r = 0; r < size(nums); ++r) {
            if (nums[r] == 0) continue;
            swap(nums[l], nums[r]);
            ++l;
        }
    }
};
