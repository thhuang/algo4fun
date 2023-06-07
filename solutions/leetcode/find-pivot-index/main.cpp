class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0, v = 0; i < nums.size(); ++i) {
            if (v * 2 + nums[i] == sum) return i;
            v += nums[i];
        }
        return -1;
    }
};
