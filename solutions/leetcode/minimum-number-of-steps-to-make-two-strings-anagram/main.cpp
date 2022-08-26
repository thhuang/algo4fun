class Solution {
   public:
    int minSteps(string s, string t) {
        array<int, 26> diff;
        diff.fill(0);
        for (int i = 0; i < s.size(); ++i) {
            ++diff[s[i] - 'a'];
            --diff[t[i] - 'a'];
        }
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            result += max(0, diff[i]);
        }
        return result;
    }
};
