class Solution {
   public:
    string reverseWords(string s) {
        string t;
        for (char c : s) {
            if (!t.empty() && t.back() == ' ' && c == ' ') {
                continue;
            } else if (t.empty() && c == ' ') {
                continue;
            } else {
                t += c;
            }
        }

        if (!t.empty() && t.back() == ' ') t.pop_back();

        reverse(t.begin(), t.end());

        for (int l = 0, r = 0; r <= t.size(); ++r) {
            if (r < t.size() && t[r] != ' ') continue;
            reverse(t.begin() + l, t.begin() + r);
            l = r + 1;
        }

        return t;
    }
};
