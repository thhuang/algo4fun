class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            stringstream ss;
            for (int j = 0; j < n; ++j) {
                ss << grid[i][j] << ' ';
            }
            ++mp[ss.str()];
        }

        int result = 0;
        for (int j = 0; j < n; ++j) {
            stringstream ss;
            for (int i = 0; i < n; ++i) {
                ss << grid[i][j] << ' ';
            }
            result += mp[ss.str()];
        }

        return result;
    }
};
