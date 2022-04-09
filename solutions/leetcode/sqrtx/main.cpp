class Solution {
   public:
    int mySqrt(int x) {
        long long l = 0, r = x / 2 + 1;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (m * m == x) return m;
            if (m * m > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
