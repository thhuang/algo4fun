class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> vis(size(isConnected), false);

        function<void(int)> dfs = [&](int u) -> void {
            if (vis[u]) return;
            vis[u] = true;
            for (int v = 0; v < size(isConnected[u]); ++v) {
                if (isConnected[u][v]) dfs(v);
            }
        };

        int count = 0;
        for (int i = 0; i < size(isConnected); ++i) {
            if (vis[i]) continue;
            ++count;
            dfs(i);
        }

        return count;
    }
};
