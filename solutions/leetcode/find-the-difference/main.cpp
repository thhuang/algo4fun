class Solution {
   public:
    char findTheDifference(string s, string t) {
        array<int, 26> freq = {};
        for (char c : s) ++freq[c - 'a'];
        for (char c : t) {
            if (--freq[c - 'a'] < 0) return c;
        }
        return ' ';
    }
};

class Solution {
   public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (char c : s) result ^= c;
        for (char c : t) result ^= c;
        return result;
    }
};
