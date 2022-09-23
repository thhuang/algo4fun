class Solution {
    const int mod = 1e9 + 7;

   public:
    int concatenatedBinary(int n) {
        long long result = 0;
        for (int i = 1, shift = 1, cnt = 1, j = 0; i <= n; ++i) {
            result = (result << shift) % mod;
            result = (result + i) % mod;

            if (++j == cnt) {
                j = 0;
                cnt <<= 1;
                ++shift;
            }
        }
        return result;
    }
};
