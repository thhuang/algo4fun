class Solution {
   public:
    int maxVacationDays(vector<vector<int>>& flights,
                        vector<vector<int>>& days) {
        int n = flights.size();
        int k = days.front().size();

        for (int i = 0; i < n; ++i) flights[i][i] = 1;

        vector<int> dp(n, -1);
        for (int to = 0; to < n; ++to) {
            if (flights[0][to]) dp[to] = days[to][0];
        }

        for (int i = 1; i < k; ++i) {
            vector<int> new_dp(n, -1);
            for (int from = 0; from < n; ++from) {
                if (dp[from] == -1) continue;
                for (int to = 0; to < n; ++to) {
                    if (flights[from][to] == 0) continue;
                    new_dp[to] = max(new_dp[to], dp[from] + days[to][i]);
                }
            }
            dp = move(new_dp);
        }

        int result = 0;
        for (int v : dp) result = max(result, v);

        return result;
    }
};
