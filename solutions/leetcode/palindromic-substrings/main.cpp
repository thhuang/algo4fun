class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (0 <= l && r < n && s[l] == s[r]) ++count, --l, ++r;
        }
        for (int i = 0; i < n - 1; ++i) {
            int l = i, r = i + 1;
            while (0 <= l && r < n && s[l] == s[r]) ++count, --l, ++r;
        }

        return count;
    }
};
