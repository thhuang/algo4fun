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
        vector<int> group(n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&group, &find](int u) -> int {
            if (u == group[u]) return u;
            return group[u] = find(group[u]);
        };

        function<void(int, int)> unite = [&group, &find](int a, int b) -> void {
            int pa = find(a);
            int pb = find(b);
            group[pa] = pb;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) unite(i, j);
            }
        }

        unordered_set<int> result;
        for (int i = 0; i < n; ++i) result.insert(find(i));

        return result.size();
    }
};
