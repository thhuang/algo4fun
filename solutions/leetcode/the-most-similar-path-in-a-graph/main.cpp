class Solution {
   public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads,
                            vector<string>& names, vector<string>& targetPath) {
        int m = targetPath.size();

        vector adj(n, vector<int>());
        for (auto& e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector dp(m, vector<int>(n, m));
        vector p(m, vector<int>(n, -1));
        for (int j = 0; j < n; ++j)
            dp[0][j] = targetPath[0] == names[j] ? 0 : 1;

        for (int i = 1; i < m; ++i) {
            for (int k = 0; k < n; ++k) {
                for (int j : adj[k]) {
                    int d = targetPath[i] == names[k] ? 0 : 1;
                    int v = dp[i - 1][j] + d;
                    if (dp[i][k] < v) continue;
                    dp[i][k] = v;
                    p[i][k] = j;
                }
            }
        }

        int u =
            min_element(dp.back().begin(), dp.back().end()) - dp.back().begin();

        vector<int> rresult;
        for (int i = m - 1; ~i; --i) {
            rresult.push_back(u);
            u = p[i][u];
        }

        return {rresult.rbegin(), rresult.rend()};
    }
};
