class Solution {
   public:
    vector<int> shortestDistanceColor(vector<int>& colors,
                                      vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> color_dist(3, vector<int>(n));
        for (int c = 0; c < 3; ++c) {
            int color = c + 1;
            for (int i = 0, d = n; i < n; ++i) {
                color_dist[c][i] = ++d;
                if (colors[i] == color) color_dist[c][i] = d = 0;
            }
            for (int i = n - 1, d = n; ~i; --i) {
                color_dist[c][i] = min(color_dist[c][i], ++d);
                if (colors[i] == color) color_dist[c][i] = d = 0;
            }
        }

        vector<int> result;
        for (const auto& q : queries) {
            int i = q[0], c = q[1] - 1;
            result.emplace_back(color_dist[c][i]);
            if (result.back() >= n) result.back() = -1;
        }

        return result;
    }
};
