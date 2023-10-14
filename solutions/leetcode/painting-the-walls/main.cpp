class Solution {
   public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        int mx = accumulate(cost.begin(), cost.end(), 0);

        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        function<int(int, int)> dp = [&](int i, int remain) -> int {
            if (remain <= 0) return 0;
            if (i == n) return mx;
            if (memo[i][remain] != -1) return memo[i][remain];

            return memo[i][remain] =
                       min(dp(i + 1, remain),
                           dp(i + 1, remain - time[i] - 1) + cost[i]);
        };

        return dp(0, n);
    }
};

class Solution {
   public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        int mx = accumulate(cost.begin(), cost.end(), 0);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, mx));
        for (int i = 0; i <= n; ++i) dp[i][0] = 0;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = min(dp[i + 1][j],
                               dp[i + 1][max(0, j - time[i] - 1)] + cost[i]);
            }
        }

        return dp[0][n];
    }
};

class Solution {
   public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        int mx = accumulate(cost.begin(), cost.end(), 0);

        vector<int> dp(n + 1, mx);
        dp[0] = 0;

        for (int i = n - 1; i >= 0; --i) {
            vector<int> dpNew(n + 1, mx);
            for (int j = 0; j <= n; ++j) {
                dpNew[j] = min(dp[j], dp[max(0, j - time[i] - 1)] + cost[i]);
            }
            dp = dpNew;
        }

        return dp[n];
    }
};

class Solution {
   public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        int mx = accumulate(cost.begin(), cost.end(), 0);

        vector<int> dp(n + 1, mx);
        dp[0] = 0;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                dp[j] = min(dp[j], dp[max(0, j - time[i] - 1)] + cost[i]);
            }
        }

        return dp[n];
    }
};
