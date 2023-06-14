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

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp;
        for (int i = 0; i < equations.size(); ++i) {
            auto a = equations[i][0];
            auto b = equations[i][1];
            auto v = values[i];
            mp[a][b] = v;
            if (v != 0) mp[b][a] = 1.0 / v;
        }

        unordered_set<string> vis;
        function<double(string, string)> dfs = [&](string a,
                                                   string t) -> double {
            if (a == t) return 1.0;
            if (mp[a].count(t) > 0 && mp[a][t] >= -1.0) return mp[a][t];
            if (vis.count(a) > 0) return -1.0;
            vis.insert(a);
            for (auto [b, v] : mp[a]) {
                if (v < 0) continue;

                auto got = dfs(b, t);
                if (got < 0) continue;

                return mp[a][t] = v * got;
            }
            return -1.0;
        };

        vector<double> result;
        for (auto& query : queries) {
            vis.clear();
            auto a = query[0];
            auto b = query[1];

            if (mp.count(a) + mp.count(b) != 2) {
                result.push_back(-1.0);
            } else {
                result.push_back(dfs(query[0], query[1]));
            }
        }

        return result;
    }
};
