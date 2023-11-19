class Solution {
   public:
    int findNthDigit(int n) {
        long long v = 0, d = 9, len = 1;
        while (true) {
            if (n - d * len < 0) break;
            n -= d * len;
            v += d;
            d *= 10;
            ++len;
        }

        v += n / len;

        if (n % len == 0) {
            return to_string(v).back() - '0';
        }

        return to_string(v + 1)[n % len - 1] - '0';
    }
};
