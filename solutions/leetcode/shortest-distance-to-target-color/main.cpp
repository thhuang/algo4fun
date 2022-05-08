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

class Solution {
   public:
    vector<int> shortestDistanceColor(vector<int>& colors,
                                      vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> color_dist(n, vector<int>(3, -1));

        color_dist.front()[colors.front() - 1] = 0;
        for (int i = 1; i < n; ++i) {
            int ci = colors[i] - 1;
            color_dist[i][ci] = 0;
            for (int j = 0; j < 3; ++j) {
                if (color_dist[i - 1][j] == -1) continue;
                if (color_dist[i][j] == -1)
                    color_dist[i][j] = color_dist[i - 1][j] + 1;
                else
                    color_dist[i][j] =
                        min(color_dist[i][j], color_dist[i - 1][j] + 1);
            }
        }

        color_dist.back()[colors.back() - 1] = 0;
        for (int i = n - 2; ~i; --i) {
            int ci = colors[i] - 1;
            color_dist[i][ci] = 0;
            for (int j = 0; j < 3; ++j) {
                if (color_dist[i + 1][j] == -1) continue;
                if (color_dist[i][j] == -1)
                    color_dist[i][j] = color_dist[i + 1][j] + 1;
                else
                    color_dist[i][j] =
                        min(color_dist[i][j], color_dist[i + 1][j] + 1);
            }
        }

        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            result[i] = color_dist[queries[i][0]][queries[i][1] - 1];
        }

        return result;
    }
};
