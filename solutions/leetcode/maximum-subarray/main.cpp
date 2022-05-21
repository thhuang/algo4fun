class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int result = numeric_limits<int>::min();
        int curr = 0;
        for (int v : nums) {
            curr = max(curr, 0) + v;
            result = max(result, curr);
        }
        return result;
    }
};
