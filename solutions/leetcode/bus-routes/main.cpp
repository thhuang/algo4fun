class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) return 0;

        int n = routes.size();

        unordered_map<int, unordered_set<int>> stopToRoutes;
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].insert(i);
            }
        }

        vector<unordered_set<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                for (int j : stopToRoutes[stop]) {
                    adj[i].insert(j);
                }
            }
        }

        unordered_set<int> targetRoutes;
        for (int r : stopToRoutes[target]) {
            targetRoutes.insert(r);
        }

        queue<pair<int, int>> q;
        for (int r : stopToRoutes[source]) {
            q.push({r, 1});
        }

        vector<bool> vis(n, false);

        while (!q.empty()) {
            auto [u, step] = q.front();
            q.pop();

            if (vis[u]) continue;
            vis[u] = true;

            if (targetRoutes.count(u) > 0) return step;

            for (int v : adj[u]) q.push({v, step + 1});
        }

        return -1;
    }
};

class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        int n = routes.size();

        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        vector<bool> visRoute(n, false);
        unordered_set<int> visStop;

        queue<pair<int, int>> q;
        q.push({source, 0});

        while (!q.empty()) {
            auto [u, step] = q.front();
            q.pop();

            if (visStop.count(u) > 0) continue;
            visStop.insert(u);

            if (u == target) return step;

            for (int i : stopToRoutes[u]) {
                if (visRoute[i]) continue;
                visRoute[i] = true;

                for (int v : routes[i]) {
                    q.push({v, step + 1});
                }
            }
        }

        return -1;
    }
};
