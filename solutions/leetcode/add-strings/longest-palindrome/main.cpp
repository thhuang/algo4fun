class Solution {
   public:
    int longestPalindrome(string s) {
        int length = 0;
        unordered_map<char, int> char_count;
        for (char c : s) {
            if (++char_count[c] == 2) {
                length += 2;
                char_count[c] -= 2;
            }
        }
        for (auto p : char_count) {
            if (p.second == 1) {
                ++length;
                break;
            }
        }
        return length;
    }
};
