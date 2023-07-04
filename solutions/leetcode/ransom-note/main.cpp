class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> cnt;
        cnt.fill(0);
        for (int c : magazine) ++cnt[c - 'a'];
        for (int c : ransomNote)
            if (--cnt[c - 'a'] < 0) return false;
        return true;
    }
};
