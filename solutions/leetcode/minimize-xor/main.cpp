class Solution {
   public:
    int minimizeXor(int num1, int num2) {
        int n1 = 0;
        for (int i = num1; i; i >>= 1) n1 += i & 1;

        int n2 = 0;
        for (int i = num2; i; i >>= 1) n2 += i & 1;

        if (n1 == n2) return num1;

        if (n1 > n2) {
            int sub = 0;
            for (int i = 0, v = 1; i < n1 - n2; ++i, v <<= 1) {
                while ((num1 & v) == 0) v <<= 1;
                sub += v;
            }
            return num1 - sub;
        }

        int add = 0;
        for (int i = 0, v = 1; i < n2 - n1; ++i, v <<= 1) {
            while ((num1 & v) != 0) v <<= 1;
            add += v;
        }

        return num1 + add;
    }
};
