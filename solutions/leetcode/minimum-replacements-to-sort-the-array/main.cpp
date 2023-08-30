class Solution {
   public:
    long long minimumReplacement(vector<int>& nums) {
        long long result = 0;
        for (int i = nums.size() - 1, mx = nums.back(); i >= 0; --i) {
            int cnt = (nums[i] - 1) / mx + 1;
            result += cnt;
            if (cnt * mx == nums[i]) continue;
            mx = nums[i] / cnt;
        }
        return result - nums.size();
    }
};
