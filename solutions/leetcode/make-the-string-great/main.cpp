class Solution {
   public:
    string makeGood(string s) {
        while (true) {
            string new_s;
            for (int i = 0; i < s.size(); ++i) {
                if (i + 1 < s.size() && s[i] != s[i + 1] &&
                    (s[i] == toupper(s[i + 1]) || s[i] == tolower(s[i + 1]))) {
                    ++i;
                } else {
                    new_s += s[i];
                }
            }
            if (new_s == s) break;
            s = new_s;
        }
        return s;
    }
};
