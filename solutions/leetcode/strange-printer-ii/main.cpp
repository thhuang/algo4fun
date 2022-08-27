class Solution {
   public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size();
        int n = targetGrid.front().size();

        unordered_set<int> colors;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                colors.insert(targetGrid[i][j]);
            }
        }

        auto unprint = [&](int c) -> bool {
            bool found = false;
            int u = numeric_limits<int>::max();
            int d = numeric_limits<int>::min();
            int l = numeric_limits<int>::max();
            int r = numeric_limits<int>::min();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (targetGrid[i][j] != c) continue;
                    found = true;
                    u = min(u, i);
                    d = max(d, i);
                    l = min(l, j);
                    r = max(r, j);
                }
            }

            if (!found) return false;

            for (int i = u; i <= d; ++i)
                for (int j = l; j <= r; ++j)
                    if (targetGrid[i][j] != c && targetGrid[i][j] != 0)
                        return false;

            for (int i = u; i <= d; ++i)
                for (int j = l; j <= r; ++j) targetGrid[i][j] = 0;

            colors.erase(c);

            return true;
        };

        while (!colors.empty()) {
            bool found = false;
            for (int c : colors) {
                if (unprint(c)) {
                    found = true;
                    break;
                };
            }
            if (!found) return false;
        }

        return true;
    }
};
