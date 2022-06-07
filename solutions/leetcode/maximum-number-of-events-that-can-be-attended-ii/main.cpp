class Solution {
   public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        vector<vector<int>> dp(events.size(), vector(k + 1, -1));

        function<int(int, int)> dfs = [&](int ei, int ki) -> int {
            if (ei >= events.size() || ki == 0) return 0;
            if (~dp[ei][ki]) return dp[ei][ki];
            int next_ei =
                upper_bound(events.begin(), events.end(), events[ei][1],
                            [](int t, const vector<int>& v) -> bool {
                                return t < v[0];
                            }) - events.begin();
            return dp[ei][ki] = max(dfs(ei + 1, ki),
                                    dfs(next_ei, ki - 1) + events[ei][2]);
        };

        return dfs(0, k);
    }
};
