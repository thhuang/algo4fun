class Solution {
   public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int result = 0;
        function<bool(int, int)> dfs = [&](int u, int p) -> bool {
            bool apple = false;
            for (int v : adj[u]) {
                if (v != p && dfs(v, u)) {
                    apple = true;
                    ++result;
                }
            }
            return apple || hasApple[u];
        };
        dfs(0, -1);

        return result * 2;
    }
};
