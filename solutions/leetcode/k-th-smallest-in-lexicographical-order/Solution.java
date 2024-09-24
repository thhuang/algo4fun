class Solution {
    public int findKthNumber(int n, int k) {
        int i = 1;
        int p = 1;
        while (i < k) {
            int sz = treeSize(p, n);
            if (i + sz <= k) {
                i += sz;
                ++p;
            } else { // i + sz > k
                i += 1;
                p *= 10;
            }
        }
        return p;
    }

    private int treeSize(int p, int n) {
        int result = 0;
        long l = p;
        long r = p + 1;
        while (l <= n) {
            result += Math.min(r, n + 1) - l;
            l *= 10;
            r *= 10;
        }
        return result;
    }
}