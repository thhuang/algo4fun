class Solution {
   public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto e : dislikes) {
            graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
        }

        vector<int> group(n + 1, -1);
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
