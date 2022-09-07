class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& f : flights) adj[f[0]].push_back({f[1], f[2]});

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;  // {cost, stops, city}
        pq.push({0, -1, src});

        vector<int> vis(n, -1);

        while (!pq.empty()) {
            auto [c, s, u] = pq.top();
            pq.pop();

            if (u == dst) return c;
            if (s == k) continue;
            if (vis[u] != -1 && vis[u] <= s) continue;
            vis[u] = s;

            for (auto [v, cc] : adj[u]) pq.push({c + cc, s + 1, v});
        }

        return -1;
    }
};
