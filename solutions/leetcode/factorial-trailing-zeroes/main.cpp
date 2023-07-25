class Solution {
   public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n) result += n /= 5;
        return result;
    }
};
