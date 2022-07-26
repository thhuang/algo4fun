class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        int total = 0;
        for (char c : s) total += c == '1';

        int n = s.size();
        int result = n - total;
        for (int i = 0, l = 0; i < s.size(); ++i) {
            l += s[i] == '1';
            int r = n - i - 1 - total + l;
            result = min(result, l + r);
        }

        return result;
    }
};
