class Solution {
   public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        queue<pair<int, int>> q;

        vector<int> vis1(n, -1);
        q.push({node1, 0});
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            if (vis1[u] != -1) continue;
            vis1[u] = d;

            if (edges[u] == -1) continue;
            q.push({edges[u], d + 1});
        }

        vector<int> vis2(n, -1);
        q.push({node2, 0});
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            if (vis2[u] != -1) continue;
            vis2[u] = d;

            if (edges[u] == -1) continue;
            q.push({edges[u], d + 1});
        }

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
