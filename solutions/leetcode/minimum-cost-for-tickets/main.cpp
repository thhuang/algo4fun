class Solution {
   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        array<int, 3> tickets = {1, 7, 30};
        vector<array<int, 3>> dp(366, {0, 0, 0});

        int d = 0;
        for (int i = 1; i <= 365; ++i) {
            if (d == days.size() || days[d] != i) {
                dp[i] = dp[i - 1];
                continue;
            }
            ++d;

            for (int t = 0; t < tickets.size(); ++t) {
                int j = i - tickets[t];
                int v = j <= 0 ? 0 : *min_element(dp[j].begin(), dp[j].end());
                dp[i][t] = v + costs[t];
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};
