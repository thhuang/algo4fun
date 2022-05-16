// https://youtu.be/TyWtx7q2D7Y
// https://youtu.be/mKUsbABiwBI
class Solution {
   public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<vector<int>> result;
        vector<int> vis(n, -1);
        function<int(int, int, int)> dfs = [&](int u, int p, int rank) -> int {
            if (vis[u] != -1) return vis[u];
            vis[u] = rank;

            int min_rank = rank;
            for (int v : adj[u]) {
                if (v == p) continue;
                int returned_rank = dfs(v, u, rank + 1);
                if (returned_rank == rank + 1) result.push_back({u, v});
                min_rank = min(min_rank, returned_rank);
            }

            return min_rank;
        };

        dfs(0, -1, 0);

        return result;
    }
};
