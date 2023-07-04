class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, bool> mapped;
        unordered_map<char, char> mp;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(s[i]) == 0) {
                if (mapped[t[i]]) return false;
                mapped[t[i]] = true;
                mp[s[i]] = t[i];
            }
            s[i] = mp[s[i]];
        }
        return s == t;
    }
};
