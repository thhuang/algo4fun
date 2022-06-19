class Solution {
    const long long mod = 1e9 + 7;

   public:
    int findDerangement(int n) {
        int sign = (n % 2 == 0) ? 1 : -1;
        long long result = sign;
        for (long long i = n, v = 1; i > 0; --i) {
            v = v * i % mod;
            sign = -sign;
            result = (result + sign * v) % mod;
        }

        if (result < 0) result += mod;
        return result;
    }
};
