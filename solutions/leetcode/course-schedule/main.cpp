class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& p : prerequisites) adj[p[0]].push_back(p[1]);

        vector<int> vis(numCourses, 0);
        function<bool(int)> dfs = [&](int u) -> bool {
            vis[u] = 1;

            for (int v : adj[u]) {
                if (vis[v] == 2) continue;
                if (vis[v] == 1 || !dfs(v)) return false;
            }

            vis[u] = 2;
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (vis[i]) continue;
            if (!dfs(i)) return false;
        }

        return true;
    }
};
