class Solution {
   public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> result(n, 1);
        function<array<int, 26>(int, int)> dfs = [&](int u,
                                                     int p) -> array<int, 26> {
            array<int, 26> res;
            fill(res.begin(), res.end(), 0);

            for (int v : adj[u]) {
                if (v == p) continue;
                auto cnt = dfs(v, u);
                for (int i = 0; i < 26; ++i) res[i] += cnt[i];
            }

            result[u] = ++res[labels[u] - 'a'];

            return res;
        };

        dfs(0, -1);

        return result;
    }
};
