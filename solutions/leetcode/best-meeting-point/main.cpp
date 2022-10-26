class Solution {
   public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<int> rows, cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int mr = rows[rows.size() / 2];
        int mc = cols[cols.size() / 2];

        int result = 0;
        for (int r : rows) result += abs(r - mr);
        for (int c : cols) result += abs(c - mc);

        return result;
    }
};
