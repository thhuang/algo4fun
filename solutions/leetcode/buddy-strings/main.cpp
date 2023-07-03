class Solution {
   public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        if (s == goal) {
            array<bool, 26> seen;
            seen.fill(false);

            for (char c : s) {
                if (seen[c - 'a']) return true;
                seen[c - 'a'] = true;
            }
            return false;
        }

        int i = -1, j = -1;
        for (int k = 0; k < s.size(); ++k) {
            if (s[k] == goal[k]) continue;
            if (i == -1) {
                i = k;
            } else if (j == -1) {
                j = k;
            } else {
                return false;
            }
        }

        if (j == -1) return false;

        swap(s[i], s[j]);
        return s == goal;
    }
};
