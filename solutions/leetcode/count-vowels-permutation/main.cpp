class Solution {
    const int mod = 1e9 + 7;
    typedef long long ll;

   public:
    int countVowelPermutation(int n) {
        ll a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 1; k < n; ++k) {
            tie(a, e, i, o, u) = tuple<ll, ll, ll, ll, ll>{
                (e + i + u) % mod,  // a
                (a + i) % mod,      // e
                (e + o) % mod,      // i
                i,                  // o
                (i + o) % mod,      // u
            };
        }
        return (a + e + i + o + u) % mod;
    }
};
