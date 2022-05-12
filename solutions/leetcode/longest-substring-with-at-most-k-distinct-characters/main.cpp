class Solution {
   public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> char_count;
        int result = 0;

        for (int l = 0, r = 0; r < s.size(); ++r) {
            ++char_count[s[r]];

            while (char_count.size() > k) {
                if (--char_count[s[l]] == 0) char_count.erase(s[l]);
                ++l;
            }

            result = max(result, r - l + 1);
        }

        return result;
    }
};
