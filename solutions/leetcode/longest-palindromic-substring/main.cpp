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

class Solution {
   public:
    string longestPalindrome(string s) {
        string result;
        for (int i = 0; i < s.size(); ++i) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) --l, ++r;
            if (result.size() < r - l - 1) result = s.substr(l + 1, r - l - 1);

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) --l, ++r;
            if (result.size() < r - l - 1) result = s.substr(l + 1, r - l - 1);
        }
        return result;
    }
};

class Solution {
   public:
    string longestPalindrome(string s) {
        string result;

        auto search = [&](int l, int r) {
            while (0 <= l && r < s.size() && s[l] == s[r]) --l, ++r;
            if (r - l - 1 > result.size()) result = s.substr(l + 1, r - l - 1);
        };

        for (int i = 0; i < s.size(); ++i) {
            search(i, i);
            search(i, i + 1);
        }

        return result;
    }
};
