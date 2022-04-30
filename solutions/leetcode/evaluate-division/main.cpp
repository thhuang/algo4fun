class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];
            graph[a][b] = v;
            graph[b][a] = 1 / v;
        }

        unordered_set<string> vis;
        function<void(string)> dfs = [&](string u) -> void {
            if (!graph.count(u)) return;
            if (vis.count(u)) return;
            vis.insert(u);
            for (auto [v, v_val] : graph[u]) {
                dfs(v);
                for (auto [w, w_val] : graph[v]) {
                    graph[u][w] = v_val * w_val;
                    graph[w][u] = 1 / graph[u][w];
                }
            }
        };

        vector<double> result(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            string a = queries[i][0], b = queries[i][1];
            dfs(a);
            if (auto it = graph[a].find(b); it != graph[a].end())
                result[i] = it->second;
        }

        return result;
    }
};
