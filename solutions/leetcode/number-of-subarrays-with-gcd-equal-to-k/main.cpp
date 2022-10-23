class Solution {
   public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        for (int l = 0; l < n; ++l) {
            int v = nums[l];
            for (int r = l; r < n; ++r) {
                v = gcd(v, nums[r]);
                if (v == k) {
                    ++result;
                } else if (v < k) {
                    break;
                }
            }
        }
        return result;
    }
};
