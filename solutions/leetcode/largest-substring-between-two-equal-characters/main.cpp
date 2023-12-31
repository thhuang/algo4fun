class Solution {
   public:
    int maxLengthBetweenEqualCharacters(string s) {
        array<int, 26> charIndex;
        fill(charIndex.begin(), charIndex.end(), -1);

        int result = -1;
        for (int r = 0; r < s.size(); ++r) {
            int l = charIndex[s[r] - 'a'];
            if (l == -1) {
                charIndex[s[r] - 'a'] = r;
            } else {
                result = max(result, r - l - 1);
            }
        }

        return result;
    }
};
