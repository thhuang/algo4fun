class Solution {
   public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += k * 2) {
            int l = i, r = min((int)s.size(), i + k);
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};
