class Solution {
   public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n);
        for (const auto& r : relations) {
            adj[r[0] - 1].push_back(r[1] - 1);
        }

        vector<int> depth(n);
        vector<int> vis(n, 0);

        function<int(int)> dfs = [&](int u) -> int {
            vis[u] = 1;

            int d = 0;
            for (int v : adj[u]) {
                if (vis[v] == 1) return -1;
                if (vis[v] == 2) {
                    d = max(d, depth[v]);
                    continue;
                }

                int res = dfs(v);
                if (res == -1) return -1;
                d = max(d, res);
            }

            vis[u] = 2;
            return depth[u] = d + 1;
        };

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            if (dfs(i) == -1) return -1;
            result = max(result, dfs(i));
        }

        return result;
    }
};
