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

class Solution {
   public:
    string reverseWords(string s) {
        for (int l = 0; l < s.size(); ++l) {
            int r = find(s.begin() + l, s.end(), ' ') - s.begin();
            reverse(s.begin() + l, s.begin() + r);
            l = r;
        }
        return s;
    }
};

class Solution {
   public:
    string reverseWords(string s) {
        int l = 0;
        for (int r = 0; r <= s.size(); ++r) {
            if (r == s.size() || s[r] == ' ') {
                reverse(s.begin() + l, s.begin() + r);
                l = r + 1;
            }
        }
        return s;
    }
};
