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

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const vector<int>& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> longest_path;
        vector<int> curr;

        function<void(int, int)> dfs = [&](int u, int p) -> void {
            curr.push_back(u);

            if ((adj[u].empty() || (adj[u].size() == 1 && adj[u][0] == p)) &&
                curr.size() > longest_path.size())
                longest_path = curr;
            for (int v : adj[u]) {
                if (v != p) dfs(v, u);
            }

            curr.pop_back();
        };

        auto clear = [&]() -> void {
            longest_path.clear();
            curr.clear();
        };

        dfs(0, -1);
        int a = longest_path.back();
        clear();

        dfs(a, -1);

        int m = longest_path.size() / 2;
        if (longest_path.size() % 2 == 1) return {longest_path[m]};
        return {longest_path[m - 1], longest_path[m]};
    }
};
