class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int a = 0;
        int max_dist = 0;
        function<void(int, int, int)> dfs0 = [&](int u, int p, int d) -> void {
            if (d > max_dist) a = u, max_dist = d;
            for (int v : adj[u]) {
                if (v == p) continue;
                dfs0(v, u, d + 1);
            }
        };
        dfs0(0, -1, 1);

        vector<int> path;
        function<bool(int, int, int)> dfs1 = [&](int u, int p, int d) -> bool {
            if (d >= max_dist && adj[u].size() < 2) {
                path = {u};
                max_dist = d;
                return true;
            }

            bool res = false;
            for (int v : adj[u]) {
                if (v == p) continue;
                if (dfs1(v, u, d + 1)) {
                    res = true;
                    path.push_back(u);
                }
            }
            return res;
        };
        dfs1(a, -1, 1);

        int i = path.size() / 2;
        if (path.size() % 2 == 0) return {path[i - 1], path[i]};
        return {path[i]};
    }
};

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        deque<array<int, 2>> q = {{0, -1}};
        int a;
        while (!q.empty()) {
            auto [u, p] = q.front();
            q.pop_front();

            a = u;
            for (int v : adj[u]) {
                if (v == p) continue;
                q.push_back({v, u});
            }
        }

        q.push_back({a, -1});
        vector<int> parent(n, -1);
        int b;
        while (!q.empty()) {
            auto [u, p] = q.front();
            q.pop_front();

            parent[u] = p;
            b = u;
            for (int v : adj[u]) {
                if (v == p) continue;
                q.push_back({v, u});
            }
        }

        vector<int> path;
        while (a ^ b) {
            path.push_back(b);
            b = parent[b];
        }
        path.push_back(b);

        int l2 = path.size() / 2;
        if (path.size() & 1) return {path[l2]};
        return {path[l2 - 1], path[l2]};
    }
};
