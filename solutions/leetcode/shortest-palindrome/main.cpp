class Solution {
   public:
    string shortestPalindrome(string s) {
        if (s.size() < 2) return s;

        int n = s.size();

        auto check = [&](int l, int r) -> bool {
            while (0 <= l && s[l] == s[r]) --l, ++r;
            return l < 0;
        };

        int last = 0;
        for (int i = (n - 1) / 2; ~i; --i) {
            if (check(i, i)) last = max(last, i * 2);

            int l = i, r = i + 1;
            if (n & 1) --l, --r;
            if (check(l, r)) last = max(last, l * 2 + 1);
        }

        string result = s.substr(last + 1);
        reverse(result.begin(), result.end());
        result += s;

        return result;
    }
};
