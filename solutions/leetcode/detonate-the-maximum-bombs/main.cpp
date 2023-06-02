class Solution {
    bool willTrigger(vector<int>& a, vector<int>& b) {
        long long dx = a[0] - b[0];
        long long dy = a[1] - b[1];
        long long r = a[2];
        return r * r >= dx * dx + dy * dy;
    }

   public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && willTrigger(bombs[i], bombs[j])) {
                    adj[i].push_back(j);
                }
            }
        }

        function<int(int, vector<bool>&)> dfs = [&](int u,
                                                    vector<bool>& vis) -> int {
            if (vis[u]) return 0;
            vis[u] = true;
            int t = 1;
            for (int v : adj[u]) t += dfs(v, vis);
            return t;
        };

        int result = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> vis(n, false);
            result = max(result, dfs(i, vis));
        }

        return result;
    }
};
