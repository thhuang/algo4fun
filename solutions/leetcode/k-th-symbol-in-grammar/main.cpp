class Solution {
   public:
    int kthGrammar(int n, int k) {
        int l = 0, r = pow(2, n - 1);
        int u = 0;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (k - 1 < m) {
                r = m;
                u = (u == 0) ? 0 : 1;
            } else {  // k - 1 >= m
                l = m;
                u = (u == 0) ? 1 : 0;
            }
        }
        return u;
    }
};
