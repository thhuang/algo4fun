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
