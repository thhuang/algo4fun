class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = 0;
        int sum = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum >= target) {
                int length = r - l + 1;
                result = result == 0 ? length : min(result, length);
                sum -= nums[l++];
            }
        }
        return result;
    }
};
