class Solution {
   public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int result = 0;
        unordered_map<char, int> window;
        int cnt = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (++window[s[r]] == 1) ++cnt;
            while (cnt > 2) {
                if (--window[s[l++]] == 0) --cnt;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
