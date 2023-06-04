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

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> rank(n, 0);
        vector<int> group(n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int k) -> int {
            if (group[k] == k) return k;
            return group[k] = find(group[k]);
        };

        function<bool(int, int)> unite = [&](int a, int b) -> bool {
            int ga = find(a);
            int gb = find(b);
            if (ga == gb) return false;

            if (rank[ga] > rank[gb]) {
                group[gb] = ga;
            } else if (rank[gb] > rank[ga]) {
                group[ga] = gb;
            } else {
                ++rank[ga];
                group[gb] = ga;
            }
            return true;
        };

        int result = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 0) continue;
                if (unite(i, j)) {
                    --result;
                }
            }
        }

        return result;
    }
};
