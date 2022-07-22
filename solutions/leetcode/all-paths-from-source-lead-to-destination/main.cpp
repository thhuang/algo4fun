class Solution {
   public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source,
                            int destination) {
        vector<vector<int>> adj(n);
        for (const vector<int> e : edges) adj[e[0]].push_back(e[1]);
        if (!adj[destination].empty()) return false;

        vector<int> vis(n, 0);
        vis[destination] = 2;

        function<bool(int)> dfs = [&](int u) -> bool {
            if (vis[u]) return vis[u] == 2;
            if (adj[u].empty()) return false;

            vis[u] = 1;
            for (int v : adj[u]) {
                if (!dfs(v)) return false;
            }
            vis[u] = 2;

            return true;
        };

        return dfs(source);
    }
};
