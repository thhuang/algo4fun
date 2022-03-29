class Solution {
   public:
    string reverseWords(string s) {
        s.push_back(' ');
        int l = 0, r = 0;
        while (r < s.size()) {
            if (s[r] == ' ') {
                reverse(s.begin() + l, s.begin() + r);
                l = r + 1;
            }
            ++r;
        }
        s.pop_back();
        return s;
    }
};
