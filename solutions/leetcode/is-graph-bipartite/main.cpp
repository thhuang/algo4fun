class Solution {
   public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> group(n, -1);
        function<bool(int, int)> dfs = [&](int u, int g) -> bool {
            if (group[u] != -1) return group[u] == g;
            group[u] = g;
            for (int v : graph[u]) {
                if (!dfs(v, g ^ 1)) return false;
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (group[i] != -1) continue;
            if (!dfs(i, 0)) return false;
        }
        return true;
    }
};

class Solution {
   public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> group(n, 0);

        function<bool(int, int)> dfs = [&](int u, int expected_group) -> bool {
            if (group[u]) return group[u] == expected_group;
            group[u] = expected_group;

            int opposite_group = 1;
            if (expected_group == 1) opposite_group = 2;

            for (int v : graph[u]) {
                if (!dfs(v, opposite_group)) return false;
            }

            return true;
        };

        for (int i = 0; i < n; ++i) {
            if (group[i]) continue;
            if (!dfs(i, 1)) return false;
        }

        return true;
    }
};
