class Solution {
    const int mod = 1e9 + 7;

    struct Entry {
        long long a, e, i, o, u;
    };

   public:
    int countVowelPermutation(int n) {
        Entry dp = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; ++i) {
            dp = {
                (dp.e + dp.i + dp.u) % mod,  // a
                (dp.a + dp.i) % mod,         // e
                (dp.e + dp.o) % mod,         // i
                dp.i,                        // o
                (dp.i + dp.o) % mod,         // u
            };
        }
        return (dp.a + dp.e + dp.i + dp.o + dp.u) % mod;
    }
};
