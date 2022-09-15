class Solution {
   public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> char_count;

        int result = 0;
        for (int l = 0, r = 0, c = 0; r < s.size(); ++r) {
            if (++char_count[s[r]] == 1) ++c;
            while (c > 2) {
                if (--char_count[s[l++]] == 0) --c;
            }
            result = max(result, r - l + 1);
        }

        return result;
    }
};
