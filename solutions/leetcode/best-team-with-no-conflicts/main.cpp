class Solution {
   public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();

        vector<pair<int, int>> players(n);
        for (int i = 0; i < n; ++i) players[i] = {ages[i], scores[i]};
        sort(players.begin(), players.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
                 if (a.first != b.first) return a.first < b.first;
                 return a.second < b.second;
             });

        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (players[j].second > players[i].second) continue;
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += players[i].second;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
