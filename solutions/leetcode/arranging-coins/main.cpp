class Solution {
   public:
    int arrangeCoins(int n) {
        int l = 1, r = n / 2 + 1;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long v = m * (1 + m) / 2;
            if (v <= n) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l - 1;
    }
};
