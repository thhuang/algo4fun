class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int x = right - left;
        int result = left & right;
        while (x) {
            result &= ~x;
            x >>= 1;
        }
        return result;
    }
};

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int result = left & right;
        for (int i = 0, diff = right - left; i < 31; ++i) {
            int mask = 1 << i;
            if ((diff >= mask) || (left & right & mask == 0)) result &= ~mask;
        }
        return result;
    }
};
