class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int neg_count = 0;
        for (int v : nums) {
            if (v == 0) return 0;
            neg_count += v > 0 ? 0 : 1;
        }
        return neg_count & 1 ? -1 : 1;
    }
};
