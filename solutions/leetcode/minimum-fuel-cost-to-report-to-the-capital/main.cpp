class Solution {
   public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (vector<int>& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        long long result = 0;
        function<int(int, int)> dfs = [&](int u, int p) -> int {
            int cnt = 1;
            for (int v : adj[u]) {
                if (v == p) continue;
                int c = dfs(v, u);
                result += (c - 1) / seats + 1;
                cnt += c;
            }
            return cnt;
        };
        dfs(0, -1);

        return result;
    }
};
