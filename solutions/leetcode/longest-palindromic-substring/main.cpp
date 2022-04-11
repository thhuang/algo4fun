class Solution {
   public:
    string longestPalindrome(string s) {
        string result;
        auto search = [&](int l, int r) -> void {
            while (l >= 0 && r < s.size() && s[l] == s[r]) --l, ++r;
            if (r - l - 1 > result.size()) {
                result = s.substr(l + 1, r - l - 1);
            }
        };
        for (int i = 0; i < s.size(); ++i) {
            search(i, i);
        }
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] != s[i + 1]) continue;
            search(i, i + 1);
        }
        return result;
    }
};
