class Solution {
   public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        s.push_back(' ');
        for (int l = 0; l < s.size(); ++l) {
            int r = l;
            while (s[r] != ' ') ++r;
            reverse(s.begin() + l, s.begin() + r);
            l = r;
        }
        s.pop_back();
    }
};
