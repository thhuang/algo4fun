class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<array<int, 2>>> adj(n);
        for (const auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> price_required(n, numeric_limits<int>::max());
        vector<int> stops_required(n, numeric_limits<int>::max());

        // {price, city, stops}
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
        q.push({0, src, -1});

        while (!q.empty()) {
            auto [price, u, stops] = q.top();
            q.pop();

            if (u == dst) return price;
            if (stops == k) continue;
            if (price >= price_required[u] && stops >= stops_required[u])
                continue;

            price_required[u] = price;
            stops_required[u] = stops;

            for (auto [v, p] : adj[u]) q.push({price + p, v, stops + 1});
        }

        return -1;
    }
};
