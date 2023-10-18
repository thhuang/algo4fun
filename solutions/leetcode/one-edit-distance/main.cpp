class Solution {
   public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() == t.size()) {
            int diff = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != t[i]) ++diff;
            }
            return diff == 1;
        } else if (s.size() + 1 == t.size()) {
            bool foundDiff = false;
            for (int i = 0, j = 0; i < s.size() && j < t.size(); ++i, ++j) {
                if (s[i] != t[j]) {
                    if (foundDiff) return false;
                    foundDiff = true;
                    --i;
                }
            }
            return true;
        } else if (s.size() - 1 == t.size()) {
            bool foundDiff = false;
            for (int i = 0, j = 0; i < s.size() && j < t.size(); ++i, ++j) {
                if (s[i] != t[j]) {
                    if (foundDiff) return false;
                    foundDiff = true;
                    --j;
                }
            }
            return true;
        }
        return false;
    }
};
