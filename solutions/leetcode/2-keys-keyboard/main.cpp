class Solution {
   public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        dp[1] = 0;
        for (int i = 2; i < n / 2; ++i) {
            for (int j = i + i, steps = dp[i] + 2; j <= n; j += i, ++steps) {
                dp[j] = min(dp[j], steps);
            }
        }
        return dp.back();
    }
};

class Solution {
   public:
    int minSteps(int n) {
        int result = 0;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                result += i;
                n /= i;
            }
        }
        return result;
    }
};
