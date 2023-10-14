class Solution {
    bool isSimpleMatch(const string& s, const string& p) {
        for (int i = 0; i < s.size(); ++i) {
            if (p[i] != '?' && s[i] != p[i]) return false;
        }
        return true;
    }

    bool isWildcardMatch(string& s, string& p) {
        auto len = find(p.rbegin(), p.rend(), '*') - p.rbegin();
        int n = s.size(), m = p.size();

        if (n < len || !isSimpleMatch(s.substr(n - len), p.substr(m - len)))
            return false;
        if (m == len) return n == m;

        s = s.substr(0, n - len), p = p.substr(0, m - len);
        n -= len, m -= len;

        while (!p.empty() && p.back() == '*') p.pop_back();

        while (true) {
            if (isWildcardMatch(s, p)) return true;
            if (s.empty()) break;
            s.pop_back();
        }

        return false;
    }

   public:
    bool isMatch(string s, string p) { return isWildcardMatch(s, p); }
};
