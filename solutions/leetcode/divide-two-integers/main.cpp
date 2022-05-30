class Solution {
   public:
    int divide(int dividend, int divisor) {
        bool neg = (dividend < 0) ^ (divisor < 0);

        unsigned x = abs(dividend);
        unsigned y = abs(divisor);

        int yi = 0;
        while (y) ++yi, y >>= 1;
        y = abs(divisor);

        unsigned q = 0;
        for (int i = 32 - yi; ~i; --i) {
            unsigned d = (y << i);

            if (d > x) continue;

            x -= d;
            q += (1 << i);
        }

        if (neg) return -q;
        return min(q, (unsigned)numeric_limits<int>::max());
    }
};
