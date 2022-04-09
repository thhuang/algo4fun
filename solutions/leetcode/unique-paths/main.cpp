class Solution {
   public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        for (long long i = 1, j = 1, k = 1; i <= m + n - 2; ++i) {
            result *= i;
            if (i <= m - 1) {
                result /= j++;
            } else {
                result /= k++;
            }
        }
        return result;
    }
};

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp.back();
    }
};
