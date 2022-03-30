class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int ans = numeric_limits<int>::min();
        int local_max = numeric_limits<int>::min();
        for (int v : nums) {
            local_max = max(local_max, 0) + v;
            ans = max(ans, local_max);
        }
        return ans;
    }
};
