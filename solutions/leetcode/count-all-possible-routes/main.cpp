class Solution {
    const int mod = 1e9 + 7;

   public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));

        function<int(int, int)> dfs = [&](int i, int f) {
            if (f < 0) return 0;
            if (dp[i][f] != -1) return dp[i][f];

            long long result = 0;
            if (i == finish) ++result;

            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                int cost = abs(locations[i] - locations[j]);
                (result += dfs(j, f - cost)) %= mod;
            }

            return dp[i][f] = result;
        };

        return dfs(start, fuel);
    }
};
