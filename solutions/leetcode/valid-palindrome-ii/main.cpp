class Solution {
   public:
    bool validPalindrome(string s) {
        auto check = [&](int l, int r) -> bool {
            for (int i = 0; i < (r - l + 1) / 2; ++i) {
                if (s[l + i] != s[r - i]) return false;
            }
            return true;
        };

        for (int i = 0; i < size(s); ++i) {
            if (s[i] == s[size(s) - i - 1]) continue;
            return check(i + 1, size(s) - i - 1) || check(i, size(s) - i - 2);
        }
        return true;
    }
};
