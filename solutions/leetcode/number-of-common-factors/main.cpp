class Solution {
   public:
    int commonFactors(int a, int b) {
        int n = max(a, b);
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (a % i == 0 && b % i == 0) ++result;
        }
        return result;
    }
};
