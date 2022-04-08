class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i < 16; ++i) {
            uint32_t left_mask = 1 << (31 - i);
            uint32_t right_mask = 1 << i;
            if (bool(n & left_mask) == bool(n & right_mask)) continue;
            n = n ^ left_mask ^ right_mask;
        }
        return n;
    }
};
