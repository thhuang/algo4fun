class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];
            adj[a].push_back({b, p});
            adj[b].push_back({a, p});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1, start});

        vector<double> dp(n, 0);
        dp[start] = 1;

        while (!pq.empty()) {
            auto [v, a] = pq.top();
            pq.pop();

            if (a == end) return v;

            for (auto [b, p] : adj[a]) {
                if (v * p <= dp[b]) continue;

                dp[b] = v * p;
                pq.push({dp[b], b});
            }
        }

        return 0;
    }
};
