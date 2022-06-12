class Solution {
    bool isSimpleMatch(string& s, string& p) {
        if (s.size() != p.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (p[i] == '.') continue;
            if (s[i] != p[i]) return false;
        }
        return true;
    }

    bool isRegexMatch(string s, string p) {
        while (!s.empty() && !p.empty()) {
            auto it = find(p.rbegin(), p.rend(), '*');

            int length = it - p.rbegin();
            if (s.size() < length) return false;

            if (length > 0) {
                string sub_s, sub_p;
                for (int i = 0; i < length; ++i) {
                    sub_s += s.back(), s.pop_back();
                    sub_p += p.back(), p.pop_back();
                }
                if (!isSimpleMatch(sub_s, sub_p)) return false;
            }

            if (s.empty() || p.empty()) break;

            p.pop_back();  // pop '*'
            char c = p.back();
            p.pop_back();
            while (!s.empty() && (c == '.' || s.back() == c)) {
                if (isRegexMatch(s, p)) return true;
                s.pop_back();
            }
        }

        if (p.empty()) return s.empty();
        while (!p.empty()) {
            if (p.back() != '*') return false;
            p.pop_back(), p.pop_back();
        }
        return true;
    }

   public:
    bool isMatch(string s, string p) { return isRegexMatch(s, p); }
};

class Solution {
   public:
    bool isMatch(string s, string p) {
        while (s.size() && p.size()) {
            if (s.back() == p.back() || p.back() == '.') {
                s.pop_back();
                p.pop_back();
                continue;
            }

            if (p.back() != '*') return false;
            p.pop_back();

            char t = p.back();
            p.pop_back();

            while (true) {
                if (isMatch(s, p)) return true;
                if (s.empty() || (s.back() != t && t != '.')) break;
                s.pop_back();
            }
            break;
        }

        if (s.size()) return false;
        while (p.size() && p.back() == '*') {
            p.pop_back();
            p.pop_back();
        }
        return p.empty();
    }
};
