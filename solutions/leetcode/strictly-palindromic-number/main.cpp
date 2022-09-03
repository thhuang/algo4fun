class Solution {
   public:
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; ++i) {
            string s;
            int x = n;
            while (x) {
                s += to_string(x % i);
                x /= i;
            }
            string r = s;
            reverse(r.begin(), r.end());
            if (s != r) return false;
        }
        return true;
    }
};
