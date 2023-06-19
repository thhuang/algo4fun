class Solution {
   public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            bool aa = a & mask;
            bool bb = b & mask;
            if (c & mask) {
                if (aa || bb) continue;
                ++result;
            } else {
                if (!aa && !bb) continue;
                result += aa + bb;
            }
        }
        return result;
    }
};

class Solution {
   public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;

            bool aBit = a & mask;
            bool bBit = b & mask;
            bool cBit = c & mask;

            if ((aBit || bBit) == cBit) continue;
            result += cBit ? 1 : aBit + bBit;
        }
        return result;
    }
};
