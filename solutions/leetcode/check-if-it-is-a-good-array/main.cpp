class Solution {
   public:
    bool isGoodArray(vector<int>& nums) {
        int d = nums[0];
        for (int v : nums) d = gcd(d, v);
        return d == 1;
    }
};
