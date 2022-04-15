class Solution {
   public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;

        int n3 = n / 3;
        if ((n3 & 1) ^ (n & 1)) --n3;
        int n2 = (n - 3 * n3) / 2;

        return pow(2, n2) * pow(3, n3);
    }
};
