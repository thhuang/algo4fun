class Solution {
   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = size(graph);
        if (n == 0) return {};

        vector<vector<int>> paths;
        vector<int> curr_path = {0};

        function<void(int)> dfs = [&](int u) -> void {
            if (u == n - 1) {
                paths.push_back(curr_path);
                return;
            }

            for (int v : graph[u]) {
                curr_path.push_back(v);
                dfs(v);
                curr_path.pop_back();
            }
        };

        dfs(0);

        return paths;
    }
};
