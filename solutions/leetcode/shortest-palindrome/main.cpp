class Solution {
   public:
    string shortestPalindrome(string s) {
        auto check = [&](int r) -> bool {
            for (int i = 0; i < r / 2 + 1; ++i) {
                if (s[i] != s[r - i]) return false;
            }
            return true;
        };

        for (int i = s.size() - 1; ~i; --i) {
            if (check(i)) {
                string result = s.substr(i + 1);
                reverse(result.begin(), result.end());
                return result + s;
            }
        }

        return "";
    }
};
