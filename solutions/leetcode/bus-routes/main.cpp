class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        unordered_map<int, vector<int>> stop2route;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stop2route[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q;  // {stop, bus}
        q.push({source, 0});

        unordered_set<int> visited_stop = {source};
        vector<int> visited_route(routes.size(), false);

        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            if (u == target) return d;

            for (int i : stop2route[u]) {
                if (visited_route[i]) continue;
                visited_route[i] = true;

                for (int v : routes[i]) {
                    if (visited_stop.count(v) == 1) continue;
                    visited_stop.insert(v);
                    q.push({v, d + 1});
                }
            }
        }

        return -1;
    }
};
