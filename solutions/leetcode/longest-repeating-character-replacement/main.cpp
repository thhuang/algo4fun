class Solution {
   public:
    int characterReplacement(string s, int k) {
        int result = 0;
        for (char c = 'A'; c <= 'Z'; ++c) {
            int diff = 0;
            for (int l = 0, r = 0; r < s.size(); ++r) {
                if (s[r] != c) ++diff;
                while (diff > k) {
                    if (s[l++] != c) --diff;
                }
                result = max(result, r - l + 1);
            }
        }
        return result;
    }
};
