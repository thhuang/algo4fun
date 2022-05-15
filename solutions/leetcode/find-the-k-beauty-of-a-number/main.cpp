class Solution {
   public:
    int divisorSubstrings(int num, int k) {
        int count = 0;
        for (int i = 1, v = 0, base = 1, x = num; x; ++i, x /= 10) {
            v += (x % 10) * base;
            if (i < k) {
                base *= 10;
                continue;
            }

            if (v != 0 && num % v == 0) ++count;

            v /= 10;
        }

        return count;
    }
};
