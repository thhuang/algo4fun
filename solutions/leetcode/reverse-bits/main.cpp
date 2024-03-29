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

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (uint32_t mask = 1 << 31; n; n >>= 1, mask >>= 1) {
            if (n & 1) result |= mask;
        }
        return result;
    }
};

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        auto swapBits = [&](int i, int j) -> void {
            if ((n >> i & 1) == (n >> j & 1)) return;
            n ^= 1U << i | 1U << j;
        };

        for (int i = 0; i < 16; ++i) swapBits(i, 31 - i);

        return n;
    }
};
