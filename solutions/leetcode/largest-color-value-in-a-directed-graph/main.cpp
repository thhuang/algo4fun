class Solution {
   public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (vector<int>& e : edges) {
            adj[e[0]].push_back(e[1]);
            ++indegree[e[1]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int result = 0;
        int processed = 0;  // for cycle detection
        vector<vector<int>> cnt(n, vector<int>(26));
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++processed;

            int color = colors[u] - 'a';
            result = max(result, ++cnt[u][color]);

            for (int v : adj[u]) {
                for (int c = 0; c < 26; ++c)
                    cnt[v][c] = max(cnt[v][c], cnt[u][c]);
                if (--indegree[v] == 0) q.push(v);
            }
        }

        if (processed < n) return -1;
        return result;
    }
};
