class Solution {
   public:
    double myPow(double x, int n) {
        if (x == 0) return 0;

        bool neg = n < 0;
        long k = abs(n);

        double result = 1;
        double v = x;
        while (k) {
            if (k & 1) result *= v;
            k >>= 1;
            v *= v;
        }

        if (neg) return 1 / result;
        return result;
    }
};
