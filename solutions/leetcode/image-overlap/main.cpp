class Solution {
   public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int m = img1.size();
        int n = img1.front().size();

        int result = 0;
        for (int di = 1 - m; di < m; ++di) {
            for (int dj = 1 - n; dj < n; ++dj) {
                int cnt = 0;
                for (int i = max(0, -di); max(i, i + di) < m; ++i) {
                    for (int j = max(0, -dj); max(j, j + dj) < n; ++j) {
                        if (img1[i][j] + img2[i + di][j + dj] == 2) {
                            ++cnt;
                        }
                    }
                }
                result = max(result, cnt);
            }
        }

        return result;
    }
};
