class Solution {
    const int base = 26;

   public:
    string longestDupSubstring(string s) {
        string result;
        string new_result;

        auto check = [&](int length, int mod) -> bool {
            if (length == 0) return true;

            long h = 0;
            long b = 1;
            for (int i = 0; i < length - 1; ++i) {
                h = h * base % mod;
                h = (h + s[i] - 'a') % mod;

                b = b * base % mod;
            }

            unordered_set<int> seen;
            for (int i = length - 1; i < s.size(); ++i) {
                h = h * base % mod;
                h = (h + s[i] - 'a') % mod;

                if (seen.count(h)) {
                    if (length > result.size()) {
                        new_result = s.substr(i - length + 1, length);
                    }
                    return true;
                }
                seen.insert(h);

                long d = (s[i - length + 1] - 'a') * b % mod;
                h = (h - d + mod) % mod;
            }

            return false;
        };

        int l = 0, r = s.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m, 1e9 + 7) && check(m, numeric_limits<int>::max() - 1) &&
                check(m, numeric_limits<int>::max())) {
                result = new_result;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return result;
    }
};
