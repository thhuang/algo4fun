class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> cnt;
        cnt.fill(0);
        for (char c : s) ++cnt[c - 'a'];
        for (char c : t)
            if (--cnt[c - 'a'] < 0) return false;
        return true;
    }
};

class Solution {
   public:
    bool isAnagram(string s, string t) {
        array<int, 26> cnt;
        cnt.fill(0);
        for (char c : s) ++cnt[c - 'a'];
        for (char c : t) --cnt[c - 'a'];
        for (int v : cnt)
            if (v != 0) return false;
        return true;
    }
};
