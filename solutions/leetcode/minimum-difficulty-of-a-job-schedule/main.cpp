class Solution {
   public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        vector<vector<int>> mx(n + 1, vector<int>(n + 1));
        for (int l = 1; l <= n; ++l) {
            for (int r = l, v = numeric_limits<int>::min(); r <= n; ++r) {
                mx[l][r] = v = max(v, jobDifficulty[r - 1]);
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
        dp[0][0] = 0;
        for (int r = 1; r <= n; ++r) {
            for (int l = 1; l <= r; ++l) {
                for (int k = 1; k <= d; ++k) {
                    if (dp[l - 1][k - 1] == -1) continue;
                    int v = dp[l - 1][k - 1] + mx[l][r];
                    if (dp[r][k] != -1) v = min(v, dp[r][k]);
                    dp[r][k] = v;
                }
            }
        }

        return dp[n][d];
    }
};

class Solution {
    const int inf = 1e9;

   public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, inf));
        dp[n - 1][1] = jobDifficulty[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            dp[i][1] = max(jobDifficulty[i], dp[i + 1][1]);
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int daysLeft = 2; daysLeft <= d; ++daysLeft) {
                int result = inf;
                for (int j = i, mx = 0; j < n - daysLeft + 1; ++j) {
                    mx = max(mx, jobDifficulty[j]);
                    result = min(result, mx + dp[j + 1][daysLeft - 1]);
                }
                dp[i][daysLeft] = result;
            }
        }

        return dp[0][d] < inf ? dp[0][d] : -1;
    }
};
