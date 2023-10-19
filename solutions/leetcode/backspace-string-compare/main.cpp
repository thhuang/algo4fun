class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        auto reduce = [](string str) -> string {
            string result;
            int backspace = 0;
            for (int i = str.size() - 1; ~i; --i) {
                if (str[i] == '#') {
                    ++backspace;
                    continue;
                }
                if (backspace > 0) {
                    --backspace;
                    continue;
                }
                result += str[i];
            }
            return {result.rbegin(), result.rend()};
        };
        return reduce(s) == reduce(t);
    }
};

class Solution {
    string getString(string s) {
        string result;
        for (char c : s) {
            if (c != '#') {
                result += c;
            } else if (!result.empty()) {
                result.pop_back();
            }
        }
        return result;
    }

   public:
    bool backspaceCompare(string s, string t) {
        return getString(s) == getString(t);
    }
};

class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        auto next = [](const string& s, int r) -> int {
            string result;
            int skips = 0;
            for (int i = r - 1; ~i; --i) {
                if (s[i] == '#') {
                    ++skips;
                } else if (skips) {
                    --skips;
                } else {
                    return i;
                }
            }
            return -1;
        };

        int si = next(s, s.size());
        int ti = next(t, t.size());
        while (~si && ~ti) {
            if (s[si] != t[ti]) return false;
            si = next(s, si);
            ti = next(t, ti);
        }
        return si == ti;
    }
};
