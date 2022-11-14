class Solution {
   public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int i) -> void {
            if (vis[i]) return;
            vis[i] = true;
            for (int j = 0; j < n; ++j) {
                if (stones[j][0] == stones[i][0] ||
                    stones[j][1] == stones[i][1]) {
                    dfs(j);
                }
            }
        };

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            ++cnt;
            dfs(i);
        }

        return n - cnt;
    }
};
