class Solution {
   public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture.front().size();

        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') ++row[i], ++col[j];
            }
        }

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1)
                    ++result;
            }
        }

        return result;
    }
};
