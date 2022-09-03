class Solution {
   public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat.front().size();

        int result = 0;
        vector<bool> selected(n, false);
        int count = 0;

        function<void(int)> dfs = [&](int i) -> void {
            if (count == cols) {
                unordered_set<int> unconverted;
                for (int c = 0; c < n; ++c) {
                    if (selected[c]) continue;

                    for (int r = 0; r < m; ++r) {
                        if (mat[r][c] == 1) unconverted.insert(r);
                    }
                }
                result = max(result, m - (int)unconverted.size());
                return;
            }
            if (i == n) return;

            dfs(i + 1);

            selected[i] = true;
            ++count;

            dfs(i + 1);

            selected[i] = false;
            --count;
        };

        dfs(0);

        return result;
    }
};
