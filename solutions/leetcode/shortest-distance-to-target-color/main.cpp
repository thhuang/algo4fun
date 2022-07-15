class Solution {
    const int INF = numeric_limits<int>::max();

   public:
    vector<int> shortestDistanceColor(vector<int>& colors,
                                      vector<vector<int>>& queries) {
        int n = colors.size();
        vector<array<int, 4>> dist(n, {INF, INF, INF});
        for (int i = 0; i < n; ++i) {
            dist[i][colors[i]] = 0;
            if (i == 0) continue;
            for (int c = 1; c <= 3; ++c) {
                if (dist[i - 1][c] == INF || c == colors[i]) continue;
                dist[i][c] = dist[i - 1][c] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            dist[i][colors[i]] = 0;
            if (i == n - 1) continue;
            for (int c = 1; c <= 3; ++c) {
                if (dist[i + 1][c] == INF || c == colors[i]) continue;
                dist[i][c] = min(dist[i][c], dist[i + 1][c] + 1);
            }
        }

        vector<int> result;
        for (const vector<int>& q : queries) {
            int v = dist[q[0]][q[1]];
            result.push_back(v == INF ? -1 : v);
        }
        return result;
    }
};

class Solution {
   public:
    vector<int> shortestDistanceColor(vector<int>& colors,
                                      vector<vector<int>>& queries) {
        int n = colors.size();
        vector<array<int, 3>> dist(n, {n, n, n});

        for (int c = 0; c < 3; ++c) {
            for (int i = 0, d = n; i < n; ++i) {
                dist[i][c] = ++d;
                if (c + 1 == colors[i]) dist[i][c] = d = 0;
            }
            for (int i = n - 1, d = n; i >= 0; --i) {
                dist[i][c] = min(dist[i][c], ++d);
                if (c + 1 == colors[i]) dist[i][c] = d = 0;
            }
        }

        vector<int> result;
        for (const vector<int>& q : queries) {
            int v = dist[q[0]][q[1] - 1];
            result.push_back(v >= n ? -1 : v);
        }

        return result;
    }
};
