class Solution {
   public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        
        function<int(int, int)> dfs = [&events, &dp, &dfs](int i, int k) -> int {
            if (i >= events.size() || k == 0) return 0;
            if (~dp[i][k]) return dp[i][k];
            int j = upper_bound(events.begin(), events.end(), events[i][1],
                                [](int t, const vector<int>& v) -> bool {
                                    return t < v[0];
                                }) - events.begin();
            return dp[i][k] = max(dfs(i + 1, k), dfs(j, k - 1) + events[i][2]);
        };
        
        return dfs(0, k);
    }
};

class Solution {
   public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            int j = upper_bound(events.begin(), events.end(), events[i][1],
                [](int t, vector<int>& e) -> bool {
                    return t < e[0];
                }) - events.begin();
            for (int kk = 1; kk <= k; ++kk) {
                dp[i][kk] = max(dp[i + 1][kk], dp[j][kk - 1] + events[i][2]);
            }
        }

        return dp[0][k];
    }
};
