class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
                ++l;
            } else if (!isalnum(s[r])) {
                --r;
            } else if (tolower(s[l]) != tolower(s[r])) {
                return false;
            } else {
                ++l, --r;
            }
        }
        return true;
    }
};

class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) ++l;
            while (l < r && !isalnum(s[r])) --r;
            if (l >= r) break;
            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};
