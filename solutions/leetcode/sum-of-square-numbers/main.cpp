class Solution {
   public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; ++i) {
            int l = i, r = c;
            while (l <= r) {
                long long m = l + (r - l) / 2;
                long long sum = i * i + m * m;
                if (sum == c) return true;
                if (sum > c) {
                    r = m - 1;
                } else {  // sum < c
                    l = m + 1;
                }
            }
        }
        return false;
    }
};

class Solution {
   public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; ++a) {
            long long b = sqrt(c - a * a);
            if (a * a + b * b == c) return true;
        }
        return false;
    }
};
