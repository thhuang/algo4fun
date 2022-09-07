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

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& f : flights) adj[f[0]].push_back({f[1], f[2]});

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>>
            pq;  // {cost, stop, city}
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
