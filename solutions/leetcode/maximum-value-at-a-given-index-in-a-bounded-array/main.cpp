class Solution {
   public:
    int maxValue(int n, int index, int maxSum) {
        int left = index, right = n - index - 1;

        auto calc = [&](long long v, int len) -> long long {
            if (v - len > 1) {
                return (v + v - len) * (len + 1) / 2;
            } else {
                return (v + 1) * v / 2 + len + 1 - v;
            }
        };

        auto check = [&](int v) -> bool {
            return calc(v, left) + calc(v, right) - v <= maxSum;
        };

        int l = 1, r = maxSum;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};
