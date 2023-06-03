class Solution {
   public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        vector<vector<int>> subordinates(n);
        for (int i = 0; i < n; ++i) {
            if (i == headID) continue;
            subordinates[manager[i]].push_back(i);
        }

        int result = 0;
        function<void(int, int)> dfs = [&](int u, int t) -> void {
            result = max(result, t);
            for (int v : subordinates[u]) {
                dfs(v, t + informTime[u]);
            }
        };
        dfs(headID, 0);

        return result;
    }
};
