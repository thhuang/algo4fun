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

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            nums[p++] = nums[i];
        }
        for (int i = p; i < n; ++i) {
            nums[i] = 0;
        }
    }
};
