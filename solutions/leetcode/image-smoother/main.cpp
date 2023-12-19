class Solution {
   public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img.front().size();

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                int cnt = 0;
                for (int di = -1; di <= 1; ++di) {
                    int ii = i + di;
                    if (ii < 0 || m <= ii) continue;
                    for (int dj = -1; dj <= 1; ++dj) {
                        int jj = j + dj;
                        if (jj < 0 || n <= jj) continue;
                        sum += img[ii][jj];
                        ++cnt;
                    }
                    result[i][j] = sum / cnt;
                }
            }
        }

        return result;
    }
};
