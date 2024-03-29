class Solution {
   public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n);
        for (const auto& r : relations) adj[r[0] - 1].push_back(r[1] - 1);

        vector<int> depth(n, -1);
        vector<int> vis(n, 0);
        function<int(int)> dfs = [&](int u) -> int {
            vis[u] = 1;

            int d = 0;
            for (int v : adj[u]) {
                if (vis[v] == 1) return -1;
                if (vis[v] == 2) {
                    d = max(d, depth[v]);
                } else {  // vis[v] == 0
                    int res = dfs(v);
                    if (res == -1) return -1;
                    d = max(d, res);
                }
            }

            vis[u] = 2;

            return depth[u] = d + 1;
        };

        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            if (dfs(i) == -1) return -1;
        }

        return *max_element(depth.begin(), depth.end());
    }
};

class Solution {
   public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n);
        for (auto& relation : relations) {
            adj[relation[0] - 1].push_back(relation[1] - 1);
        }

        vector<int> depth(n, -1);
        vector<bool> vis(n, false);
        function<int(int)> dfs = [&](int u) -> int {
            if (vis[u]) return depth[u];
            vis[u] = true;

            int result = 1;
            for (int v : adj[u]) {
                int d = dfs(v);
                if (d == -1) return -1;
                result = max(result, d + 1);
            }

            return depth[u] = result;
        };

        for (int i = 0; i < n; ++i) {
            if (dfs(i) == -1) return -1;
        }

        return *max_element(depth.begin(), depth.end());
    }
};
