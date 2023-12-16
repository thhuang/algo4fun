class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> charFreq = {};
        for (char c : s) ++charFreq[c - 'a'];
        for (char c : t)
            if (--charFreq[c - 'a'] < 0) return false;
        return true;
    }
};
