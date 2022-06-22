class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1);
        function<int(int)> dfs = [&](int l) -> int {
            if (l >= n) return 0;
            if (dp[l] != -1) return dp[l];

            int result = numeric_limits<int>::min();
            int v = 0;
            for (int i = l; i < l + 3 && i < n; ++i) {
                v += stoneValue[i];
                result = max(result, v - dfs(i + 1));
            }

            return dp[l] = result;
        };

        int result = dfs(0);
        return result == 0 ? "Tie" : result > 0 ? "Alice" : "Bob";
    }
};

class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, numeric_limits<int>::min());
        dp.back() = 0;
        for (int i = n - 1; ~i; --i) {
            int v = 0;
            for (int k = i; k < i + 3 && k < n; ++k) {
                v += stoneValue[k];
                dp[i] = max(dp[i], v - dp[k + 1]);
            }
        }
        return dp.front() == 0 ? "Tie" : dp.front() > 0 ? "Alice" : "Bob";
    }
};
