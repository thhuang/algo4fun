class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = size(mat);
        int m = size(mat[0]);

        vector<int> result;
        int idx = 0;
        while (k) {
            int i = idx % n;
            int j = idx / n;
            ++idx;

            if (j == 0) {
                if (mat[i][j] == 0) result.push_back(i), --k;
                continue;
            }
            if (j == m) {
                if (mat[i][j - 1] == 1) result.push_back(i), --k;
                continue;
            }
            if (mat[i][j - 1] == 1 && mat[i][j] == 0) {
                result.push_back(i), --k;
                continue;
            }
        }

        return result;
    }
};
