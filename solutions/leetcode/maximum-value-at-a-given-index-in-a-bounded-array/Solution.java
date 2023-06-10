class Solution {
    static private long calc(int len, long v) {
        if (v - len > 1) {
            return (v + v - len) * (len + 1) / 2;
        } else {
            return (v + 1) * v / 2 + len + 1 - v;
        }
    }

    static private boolean check(int n, int i, int maxSum, int v) {
        return calc(i, v) + calc(n - i - 1, v) - v <= maxSum;
    }

    public int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(n, index, maxSum, m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
}
