class Solution {
    typedef unsigned long long ull;
    const ull mod = 1LL << 32;

   public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        ull x = n + 1;
        if (x % 2 == 0) ++x;

        vector<ull> suffHash(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffHash[i] =
                ((haystack[i] - 'a') + x * suffHash[i + 1] % mod) % mod;
        }

        ull t = 0;
        ull xm = 1;
        for (int i = 0; i < m; ++i) {
            t = (t + xm * (needle[i] - 'a') % mod) % mod;
            xm = xm * x % mod;
        }

        for (int l = 0, r = l + m - 1; r < n; ++l, ++r) {
            ull v = (suffHash[l] - xm * suffHash[r + 1] % mod + mod) % mod;
            if (v == t) return l;
        }

        return -1;
    }
};

class Solution {
   public:
    int strStr(string haystack, string needle) {
        vector<int> prefix(needle.size(), 0);
        for (int i = 1; i < needle.size(); ++i) {
            int d = prefix[i - 1];
            while (d > 0 && needle[i] != needle[d]) d = prefix[d - 1];
            if (needle[i] == needle[d]) ++d;
            prefix[i] = d;
        }

        for (int i = 0, j = 0; i < haystack.size();) {
            if (haystack[i] == needle[j]) {
                ++i, ++j;
                if (j == needle.size()) return i - needle.size();
            } else {
                if (j == 0) {
                    ++i;
                } else {
                    j = prefix[j - 1];
                }
            }
        }

        return -1;
    }
};
