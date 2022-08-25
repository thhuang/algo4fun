class Solution {
    pair<int, int> bfs(const vector<vector<int>>& adj, int root) {
        queue<pair<int, int>> q;
        q.push({root, 0});

        vector<bool> vis(adj.size(), false);

        pair<int, int> result;
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            if (vis[u]) continue;
            vis[u] = true;

            result = {u, d};
            for (int v : adj[u]) q.push({v, d + 1});
        }
        return result;
    };

   public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);
        for (const vector<int>& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        auto [u, _] = bfs(adj, 0);
        auto [__, d] = bfs(adj, u);

        return d;
    }
};
