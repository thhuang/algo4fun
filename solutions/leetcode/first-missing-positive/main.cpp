class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            while (v > 0 && v != i && v < nums.size() && v != nums[v]) {
                swap(nums[i], nums[v]);
                v = nums[i];
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};
