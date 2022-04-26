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

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto distance = [&](int i, int j) -> int {
            return abs(points[i][0] - points[j][0]) +
                   abs(points[i][1] - points[j][1]);
        };

        int n = points.size();
        vector<int> min_dist(n, numeric_limits<int>::max());

        int u = 0;
        for (int i = 0; i < n; ++i) min_dist[i] = distance(u, i);

        int result = 0;
        int connected = 1;
        while (connected < n) {
            int dist = numeric_limits<int>::max();
            for (int i = 0; i < n; ++i) {
                int d = min_dist[i];
                if (d == 0) continue;
                if (d > dist) continue;
                u = i, dist = d;
            }

            result += dist;
            ++connected;

            for (int i = 0; i < n; ++i)
                min_dist[i] = min(min_dist[i], distance(u, i));
        }

        return result;
    }
};
