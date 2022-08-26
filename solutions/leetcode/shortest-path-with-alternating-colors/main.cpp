class Solution {
   public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        for (const vector<int>& e : redEdges) red[e[0]].push_back(e[1]);
        for (const vector<int>& e : blueEdges) blue[e[0]].push_back(e[1]);

        // {path, node, last color (0: red, 1: blue)}
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});
        pq.push({0, 0, 1});

        vector<array<bool, 2>> vis(n, {false, false});
        vector<int> result(n, -1);

        while (!pq.empty()) {
            auto [p, u, c] = pq.top();
            pq.pop();

            if (vis[u][c]) continue;
            vis[u][c] = true;

            result[u] = result[u] == -1 ? p : min(result[u], p);

            auto& adj = c == 0 ? blue : red;
            for (int v : adj[u]) pq.push({p + 1, v, -c + 1});
        }

        return result;
    }
};
