class Solution {
   public:
    int maximumXOR(vector<int>& nums) {
        vector<int> bit_count(27, 0);
        for (int v : nums) {
            for (int i = 0; i < 27; ++i) {
                bit_count[i] += v & 1;
                v >>= 1;
            }
        }

        int result = 0;
        for (int i = 0, k = 1; i < 27; ++i, k <<= 1) {
            if (bit_count[i]) result += k;
        }

        return result;
    }
};
