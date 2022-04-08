class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int v : nums) result ^= v;
        return result;
    }
};
