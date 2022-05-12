class Solution {
    bool isSimpleMatch(string& s, string& p) {
        for (int i = 0; i < s.size(); ++i) {
            if (p[i] == '?') continue;
            if (s[i] != p[i]) return false;
        }
        return true;
    }

    bool isWildcardMatch(string& s, string& p) {
        auto it = find(p.rbegin(), p.rend(), '*');

        int length = it - p.rbegin();
        if (length > s.size()) return false;

        string s_last = s.substr(s.size() - length, length);
        string p_last = p.substr(p.size() - length, length);

        if (!isSimpleMatch(s_last, p_last)) return false;
        if (it == p.rend()) return s.size() == p.size();

        s = s.substr(0, s.size() - length);
        p = p.substr(0, p.size() - length);
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
