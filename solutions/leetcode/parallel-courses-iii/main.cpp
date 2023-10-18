class Solution {
   public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        for (const vector<int>& r : relations) {
            adj[r[1] - 1].push_back(r[0] - 1);
        }

        vector<int> endTime(n, -1);
        function<int(int)> search = [&](int u) -> int {
            if (endTime[u] != -1) return endTime[u];
            if (adj[u].empty()) return endTime[u] = time[u];

            int mx = 0;
            for (int v : adj[u]) {
                mx = max(mx, search(v));
            }

            return endTime[u] = mx + time[u];
        };

        int result = 0;
        for (int i = 0; i < n; ++i) result = max(result, search(i));

        return result;
    }
};
