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

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<vector<int>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        int result = -1;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;

            ++result;
            vector<int> nodes = {i};

            while (!nodes.empty()) {
                int u = nodes.back();
                nodes.pop_back();

                if (vis[u]) continue;
                vis[u] = true;

                for (int v : adj[u]) nodes.push_back(v);
            }
        }

        return result;
    }
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> rank(n, 0);
        vector<int> group(n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int k) -> int {
            if (group[k] == k) return k;
            return group[k] = find(group[k]);
        };

        function<void(int, int)> unite = [&](int a, int b) -> void {
            int aa = find(a);
            int bb = find(b);
            if (aa == bb) return;
            if (rank[aa] < rank[bb]) {
                group[aa] = bb;
            } else if (rank[bb] < rank[aa]) {
                group[bb] = aa;
            } else {
                group[bb] = aa;
                ++rank[aa];
            }
        };

        for (auto& c : connections) unite(c[0], c[1]);

        unordered_set<int> s;
        for (int v : group) s.insert(find(v));

        return s.size() - 1;
    }
};
