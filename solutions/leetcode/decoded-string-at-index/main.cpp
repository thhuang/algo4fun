class Solution {
   public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                len *= s[i] - '0';
            } else {
                ++len;
            }
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            k %= len;

            if (k == 0 && !isdigit(s[i])) {
                return string(1, s[i]);
            }

            if (isdigit(s[i])) {
                len /= s[i] - '0';
            } else {
                --len;
            }
        }

        return "";
    }
};
