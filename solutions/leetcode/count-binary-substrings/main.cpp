class Solution {
   public:
    int countBinarySubstrings(string s) {
        int count = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) continue;
            int l = i - 1, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[i - 1] && s[i] == s[r])
                ++count, --l, ++r;
            i = r - 1;
        }
        return count;
    }
};
