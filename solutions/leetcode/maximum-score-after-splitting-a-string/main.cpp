class Solution {
   public:
    int maxScore(string s) {
        int n = s.size();
        int totalZeros = count(s.begin(), s.end(), '0');

        int result = 0;
        for (int i = 0, l = 0, r = n - totalZeros; i < n - 1; ++i) {
            s[i] == '0' ? ++l : --r;
            result = max(result, l + r);
        }

        return result;
    }
};
