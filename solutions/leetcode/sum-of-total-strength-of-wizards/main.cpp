// https://leetcode.com/problems/sum-of-total-strength-of-wizards/discuss/2062017/C%2B%2B-prefix-%2B-monotonic-stack-O(N)-solution-with-thought-process
class Solution {
    const int mod = 1e9 + 7;

   public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();

        vector<int> s;
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && strength[s.back()] > strength[i]) {
                right[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }

        s.clear();
        vector<int> left(n, -1);
        for (int i = n - 1; ~i; --i) {
            while (!s.empty() && strength[s.back()] >= strength[i]) {
                left[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }

        vector<long> acc(n + 1, 0);
        for (int i = 0; i < n; ++i) acc[i + 1] = (acc[i] + strength[i]) % mod;
        for (int i = 0; i < n; ++i) acc[i + 1] = (acc[i] + acc[i + 1]) % mod;

        long result = 0;
        for (int i = 0; i < n; ++i) {
            int l = left[i];
            int r = right[i];
            int ln = i - l;
            int rn = r - i;

            int rv = (acc[r] - acc[i]) * ln % mod;
            int lv = (acc[i] - acc[max(l, 0)]) * rn % mod;
            long sum = (rv - lv) % mod;

            result = result + sum * strength[i] % mod;
            result %= mod;
        }

        return (result + mod) % mod;
    }
};

class Solution {
    const int mod = 1e9 + 7;

   public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();

        vector<int> inc;
        vector<int> right(n, n - 1);
        for (int i = 0; i < n; ++i) {
            while (!inc.empty() && strength[inc.back()] > strength[i]) {
                right[inc.back()] = i - 1;
                inc.pop_back();
            }
            inc.push_back(i);
        }

        inc.clear();
        vector<int> left(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            while (!inc.empty() && strength[inc.back()] >= strength[i]) {
                left[inc.back()] = i + 1;
                inc.pop_back();
            }
            inc.push_back(i);
        }

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = (prefix[i] + strength[i]) % mod;
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = (prefix[i] + prefix[i + 1]) % mod;

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            int l = left[i];
            int r = right[i];
            int rv = (long long)(i - l + 1) * (prefix[r + 1] - prefix[i]) % mod;
            int lv = (long long)(r - i + 1) *
                     (prefix[i] - prefix[max(0, l - 1)]) % mod;

            long long sum = (rv - lv) % mod;
            result = (result + sum * strength[i] % mod) % mod;
        }

        return (result + mod) % mod;
    }
};
