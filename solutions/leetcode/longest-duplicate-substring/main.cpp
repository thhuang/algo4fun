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

class Solution {
    typedef long long ll;

    const int base = 26;
    const int mod = 1e9 + 7;

   public:
    string longestDupSubstring(string s) {
        string result;

        vector<ll> powers(s.size(), 1);
        for (ll i = 1; i < s.size(); ++i) {
            powers[i] = powers[i - 1] * base % mod;
        }

        auto check = [&](int n) -> bool {
            unordered_map<ll, vector<int>> seen;

            ll v = 0;
            for (int i = 0; i < n - 1; ++i) {
                v = (v + (s[i] - 'a') * powers[n - 1 - i] % mod) % mod;
            }

            for (int i = n - 1; i < s.size(); ++i) {
                int l = i - n + 1;
                v = (v + s[i] - 'a') % mod;

                if (auto it = seen.find(v); it != seen.end()) {
                    for (int j : it->second) {
                        if (s.compare(l, n, s, j, n) != 0) continue;
                        if (n > result.size()) result = s.substr(i - n + 1, n);
                        return true;
                    }
                }
                seen[v].push_back(i - n + 1);

                v = (v - (s[l] - 'a') * powers[n - 1] % mod + mod) % mod;
                v = v * base % mod;
            }

            return false;
        };

        int l = 0, r = s.size();
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return result;
    }
};
