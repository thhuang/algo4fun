class Solution {
   public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            string new_s;
            for (int l = 0, r; l < s.size(); l = r) {
                r = l;
                while (r < s.size() && s[l] == s[r]) ++r;
                new_s += to_string(r - l) + s[l];
            }
            s = new_s;
        }
        return s;
    }
};
