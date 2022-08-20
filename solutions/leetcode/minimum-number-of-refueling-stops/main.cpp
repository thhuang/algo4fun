class Solution {
   public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int n = stations.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) dp[i][0] = startFuel;

        for (int i = 1; i <= n; ++i) {
            int position = stations[i - 1][0];
            int fuel = stations[i - 1][1];

            for (int j = 1; j <= i; ++j) {
                if (dp[i - 1][j - 1] >= position) {
                    dp[i][j] = dp[i - 1][j - 1] + fuel;
                }
                if (dp[i - 1][j] >= position) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
            }
        }

        for (int i = 0; i <= n; ++i) {
            if (dp.back()[i] >= target) return i;
        }

        return -1;
    }
};

class Solution {
   public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int n = stations.size();

        vector<long long> dp(n + 1, 0);
        dp[0] = startFuel;

        for (int i = 1; i <= n; ++i) {
            vector<long long> new_dp(n + 1, 0);
            new_dp[0] = startFuel;

            int position = stations[i - 1][0];
            int fuel = stations[i - 1][1];

            for (int j = 1; j <= i; ++j) {
                if (dp[j - 1] >= position) {
                    new_dp[j] = dp[j - 1] + fuel;
                }
                if (dp[j] >= position) {
                    new_dp[j] = max(new_dp[j], dp[j]);
                }
            }

            dp = move(new_dp);
        }

        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) return i;
        }

        return -1;
    }
};
