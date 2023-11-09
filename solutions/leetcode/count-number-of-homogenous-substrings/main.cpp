class Solution {
    const int mod = 1e9 + 7;

   public:
    int countHomogenous(string s) {
        int n = s.size();

        long long result = 0;
        for (int l = 0, r = 0; l < n; l = r) {
            while (r < n && s[l] == s[r]) ++r;
            long long d = r - l;
            (result += (1 + d) * d / 2) %= mod;
        }

        return result;
    }
};
