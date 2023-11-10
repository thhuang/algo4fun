class Solution {
   public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        unordered_map<int, bool> vis;
        vis[adj.begin()->first] = true;

        function<void(int, vector<int>&)> dfs = [&](int u,
                                                    vector<int>& seq) -> void {
            if (vis[u]) return;
            vis[u] = true;
            seq.push_back(u);
            for (int v : adj[u]) dfs(v, seq);
        };

        vector<int> left;
        dfs(adj.begin()->second[0], left);

        vector<int> right = {adj.begin()->first};
        if (adj.begin()->second.size() > 1) {
            dfs(adj.begin()->second[1], right);
        }

        vector<int> result = {left.rbegin(), left.rend()};
        copy(right.begin(), right.end(), back_inserter(result));

        return result;
    }
};
