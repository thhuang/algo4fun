class Solution {
   public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        auto process = [&edges](vector<int>& vis, int start) -> void {
            queue<pair<int, int>> q;
            q.push({start, 0});
            while (!q.empty()) {
                auto [u, d] = q.front();
                q.pop();

                if (vis[u] != -1) continue;
                vis[u] = d;

                if (edges[u] == -1) continue;
                q.push({edges[u], d + 1});
            }
        };

        int n = edges.size();
        vector<int> vis1(n, -1);
        process(vis1, node1);
        vector<int> vis2(n, -1);
        process(vis2, node2);

        int result = -1;
        int mx = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            int a = vis1[i];
            int b = vis2[i];
            if (a == -1 || b == -1) continue;

            int d = max(a, b);
            if (d > mx) continue;
            if (d == mx) {
                result = min(result, i);
            } else {  // d < mx
                result = i;
            }
            mx = d;
        }

        return result;
    }
};
