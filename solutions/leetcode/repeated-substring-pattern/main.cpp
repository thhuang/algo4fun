class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; ++i) {
            int d = prefix[i - 1];
            while (d > 0 && s[i] != s[d]) d = prefix[d - 1];
            if (s[i] == s[d]) ++d;
            prefix[i] = d;
        }

        if (prefix.back() == 0) return false;
        return prefix.back() % (n - prefix.back()) == 0;
    }
};
