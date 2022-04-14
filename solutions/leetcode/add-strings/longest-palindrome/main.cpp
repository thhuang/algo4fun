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
