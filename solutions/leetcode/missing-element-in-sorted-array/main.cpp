class Solution {
   public:
    int missingElement(vector<int>& nums, int k) {
        int missing = 0;
        for (int i = 1; i < nums.size(); ++i) {
            missing += nums[i] - nums[i - 1] - 1;
            if (missing >= k) return nums[i] - 1 - (missing - k);
        }
        return nums.back() + k - missing;
    }
};
