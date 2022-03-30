class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> seen;
        for (int l = 0, r = 0; r < size(s); ++r) {
            while (seen.count(s[r])) {
                seen.erase(s[l++]);
            }
            seen.insert(s[r]);
            ans = max(ans, int(size(seen)));
        }
        return ans;
    }
};
