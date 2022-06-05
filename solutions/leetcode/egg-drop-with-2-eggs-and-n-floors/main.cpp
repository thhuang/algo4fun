class Solution {
   public:
    int twoEggDrop(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        static unordered_map<int, int> cache;
        if (cache.count(n)) return cache[n];

        int result = numeric_limits<int>::max();
        for (int i = 1; i <= n; ++i) {
            int v = max(i, 1 + twoEggDrop(n - i));
            result = min(result, v);
        }

        return cache[n] = result;
    }
};

class Solution {
   public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int v = max(j, 1 + dp[i - j]);
                dp[i] = min(dp[i], v);
            }
        }
        return dp.back();
    }
};

class Solution {
   public:
    int twoEggDrop(int n) {
        int checks = 0;
        int count = 0;
        while (checks < n) {
            ++count;
            checks = checks + count;
        }
        return count;
    }
};
