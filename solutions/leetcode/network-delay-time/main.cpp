class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<array<int, 2>>> graph(n + 1);
        for (auto uvw : times) graph[uvw[0]].push_back({uvw[2], uvw[1]});

        unordered_set<int> vis;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;

        int t = 0;
        q.push({0, k});
        while (!q.empty()) {
            auto [wu, u] = q.top();
            q.pop();

            if (vis.count(u)) continue;
            vis.insert(u);

            t = wu;
            for (auto [wv, v] : graph[u]) q.push({wv + wu, v});
        }

        if (vis.size() < n) return -1;
        return t;
    }
};

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<array<int, 2>>> graph(n + 1);
        for (auto uvw : times) graph[uvw[0]].push_back({uvw[2], uvw[1]});

        unordered_set<int> vis;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;

        int t = 0;
        q.push({0, k});
        while (!q.empty()) {
            auto [wu, u] = q.top();
            q.pop();

            if (vis.count(u)) continue;
            vis.insert(u);

            t = wu;
            for (auto [wv, v] : graph[u]) q.push({wv + wu, v});
        }

        if (vis.size() < n) return -1;
        return t;
    }
};
