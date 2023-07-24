class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) ++result, n &= (n - 1);
        return result;
    }
};

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) ++result, n -= n & -n;
        return result;
    }
};
