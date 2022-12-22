class Solution {
   public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> count(n, 1), result(n, 0);

        function<void(int, int)> dfs0 = [&](int u, int p) -> void {
            for (int v : adj[u]) {
                if (v == p) continue;
                dfs0(v, u);
                count[u] += count[v];
                result[u] += result[v] + count[v];
            }
        };
        dfs0(0, -1);

        function<void(int, int)> dfs1 = [&](int u, int p) -> void {
            for (int v : adj[u]) {
                if (v == p) continue;
                result[v] = result[u] + count.size() - count[v] * 2;
                dfs1(v, u);
            }
        };
        dfs1(0, -1);

        return result;
    }
};
