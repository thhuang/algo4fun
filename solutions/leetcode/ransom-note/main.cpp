class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> chars;
        fill(begin(chars), end(chars), 0);
        for (char c : magazine) ++chars[c - 'a'];
        for (char c : ransomNote) {
            if (--chars[c - 'a'] < 0) return false;
        }
        return true;
    }
};
