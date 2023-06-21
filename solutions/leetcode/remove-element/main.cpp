class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) continue;
            nums[p++] = nums[i];
        }
        return p;
    }
};
