class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> edges;
        for (int i = 1; i < n; ++i) {
            int d = abs(points[0][0] - points[i][0]) +
                    abs(points[0][1] - points[i][1]);
            edges.push({d, i});
        }

        vector<bool> vis(n, false);
        vis[0] = true;

        int result = 0;
        int connected = 1;
        while (connected < n) {
            auto [d, p] = edges.top();
            edges.pop();

            if (vis[p]) continue;
            vis[p] = true;
            ++connected;
            result += d;

            for (int i = 0; i < n; ++i) {
                if (vis[i]) continue;
                int d = abs(points[p][0] - points[i][0]) +
                        abs(points[p][1] - points[i][1]);
                edges.push({d, i});
            }
        }

        return result;
    }
};
