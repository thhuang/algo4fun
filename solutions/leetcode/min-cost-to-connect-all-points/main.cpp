class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<array<int, 2>>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int d = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);
                graph[i].push_back({d, j});
            }
        }

        vector<bool> vis(n, false);
        vis[0] = true;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>>
            connections;
        for (auto edge : graph[0]) connections.push(edge);

        int connected = 1;
        int distance = 0;
        while (connected < n) {
            auto [d, point] = connections.top();
            connections.pop();

            if (vis[point]) continue;
            vis[point] = true;
            ++connected;

            distance += d;
            for (auto edge : graph[point]) connections.push(edge);
        }

        return distance;
    }
};
