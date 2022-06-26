class Solution {
    struct Res {
        int sum, count;
    };

   public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> children(nodes);
        for (int i = 1; i < nodes; ++i) children[parent[i]].push_back(i);

        function<Res(int)> dfs = [&](int u) -> Res {
            Res res = {value[u], 1};

            for (int v : children[u]) {
                auto [s, c] = dfs(v);
                res.sum += s;
                res.count += c;
            }

            if (res.sum == 0) return {0, 0};
            return res;
        };

        return dfs(0).count;
    }
};
