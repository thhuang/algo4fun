class Solution {
   public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        for (auto r : roads) graph[r[0]].insert(r[1]), graph[r[1]].insert(r[0]);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int v = graph[i].size() + graph[j].size() -
                        (graph[i].count(j) ? 1 : 0);
                result = max(result, v);
            }
        }
        return result;
    }
};
