class Solution {
   public:
    int longestPalindrome(string s) {
        int length = 0;
        unordered_map<char, int> char_count;
        for (char c : s) {
            if (++char_count[c] % 2 == 0) length += 2;
        }
        if (s.size() > length) return length + 1;
        return length;
    }
};

class Solution {
   public:
    int longestPalindrome(string s) {
        int result = 0;
        unordered_set<int> chars;
        for (char c : s) {
            if (chars.count(c)) {
                result += 2;
                chars.erase(c);
            } else {
                chars.insert(c);
            }
        }
        return result + (chars.size() ? 1 : 0);
    }
};
