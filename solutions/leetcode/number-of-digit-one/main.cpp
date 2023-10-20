class Solution {
   public:
    int countDigitOne(int n) {
        int result = 0;

        for (long long x = 1; x <= n; x *= 10) {
            int a = n / (x * 10) * x;
            result += a;

            int b = n % (x * 10) - (x - 1);
            b = max(0, min(b, (int)x));
            result += b;
        }

        return result;
    }
};
