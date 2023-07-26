class Solution {
   public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (m * m > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
