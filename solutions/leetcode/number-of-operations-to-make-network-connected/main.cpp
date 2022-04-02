class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > size(connections) + 1) return -1;

        vector<vector<int>> graph(n);
        for (auto c : connections)
            graph[c[0]].push_back(c[1]), graph[c[1]].push_back(c[0]);

        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int u) -> void {
            if (vis[u]) return;
            vis[u] = true;
            for (int v : graph[u]) dfs(v);
        };

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            ++count;
            dfs(i);
        }

        return count - 1;
    }
};
