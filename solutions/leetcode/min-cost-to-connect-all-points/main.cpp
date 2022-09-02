class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> sz(n, 0);
        vector<int> groups(n);
        iota(groups.begin(), groups.end(), 0);

        function<int(int)> find = [&](int u) -> int {
            if (u == groups[u]) return u;
            return groups[u] = find(groups[u]);
        };

        function<void(int, int)> unite = [&](int u, int v) -> void {
            u = find(u);
            v = find(v);
            if (u == v) return;
            if (sz[u] > sz[v]) {
                sz[u] += sz[v];
                groups[v] = u;
            } else {
                sz[v] += sz[u];
                groups[u] = v;
            }
        };

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);
                pq.push({d, i, j});
            }
        }

        int result = 0;
        int edges = 0;
        while (edges < n - 1) {
            auto [d, u, v] = pq.top();
            pq.pop();

            if (find(u) == find(v)) continue;
            unite(u, v);
            result += d;
            ++edges;
        }

        return result;
    }
};

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
        for (int i = 0; i < n; ++i) min_dist[i] = distance(0, i);

        int result = 0;
        for (int connected = 1; connected < n; ++connected) {
            int u, dist = numeric_limits<int>::max();
            for (int i = 0; i < n; ++i) {
                int d = min_dist[i];
                if (d == 0 || d >= dist) continue;
                dist = d, u = i;
            }

            result += dist;

            for (int i = 0; i < n; ++i)
                min_dist[i] = min(min_dist[i], distance(u, i));
        }

        return result;
    }
};
