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
