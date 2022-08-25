class Solution {
   public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = 1 << n;

        vector<vector<bool>> vis(
            n, vector<bool>(m, false));  // {node, visited mask}

        queue<array<int, 3>> q;  // {node, path, visited mask}
        for (int i = 0; i < n; ++i) q.push({i, 0, 1 << i});

        while (!q.empty()) {
            auto [u, path, mask] = q.front();
            q.pop();

            if (vis[u][mask]) continue;
            vis[u][mask] = true;

            if (mask == m - 1) return path;

            for (int v : graph[u]) q.push({v, path + 1, mask | (1 << v)});
        }

        return n * 2;
    }
};
