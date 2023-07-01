class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) {
            if (c == s[i]) ++i;
            if (i == s.size()) break;
        }
        return i == s.size();
    }
};

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;

        int m = s.size(), n = t.size();
        for (int i = 0, j = 0; j < n; ++j) {
            if (s[i] == t[j]) {
                ++i;
                if (i == m) return true;
            }
        }

        return false;
    }
};

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        for (int i = 0, j = 0; i < s.size(); ++i, ++j) {
            while (j < n && s[i] != t[j]) ++j;
            if (j == n) return false;
        }
        return true;
    }
};
