class Solution {
   public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int n =
            max({a, b, x, *max_element(forbidden.begin(), forbidden.end())}) *
            4;
        vector<vector<bool>> vis(2, vector<bool>(n, false));
        for (int v : forbidden) {
            if (v >= n) continue;
            vis[0][v] = vis[1][v] = true;
        }

        struct Entry {
            int i, d;
            bool allow_backward;
        };

        deque<Entry> dq = {{0, 0, true}};
        while (!dq.empty()) {
            auto [i, d, allow_backward] = dq.front();
            dq.pop_front();

            if (i < 0 || i >= n) continue;
            if (i == x) return d;
            if (vis[allow_backward][i]) continue;

            vis[allow_backward][i] = true;

            dq.push_back({i + a, d + 1, true});
            if (allow_backward) dq.push_back({i - b, d + 1, false});
        }

        return -1;
    }
};
