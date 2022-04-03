class Solution {
   public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        vector<vector<int>> edges(manager.size());
        for (int i = 0; i < manager.size(); ++i) {
            if (i == headID) continue;
            edges[manager[i]].push_back(i);
        }

        int ans = 0;
        function<void(int, int)> dfs = [&](int u, int t) -> void {
            if (edges[u].empty()) {
                ans = max(ans, t);
                return;
            }
            for (int v : edges[u]) dfs(v, t + informTime[u]);
        };

        dfs(headID, 0);

        return ans;
    }
};
