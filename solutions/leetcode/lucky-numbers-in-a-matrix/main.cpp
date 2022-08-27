class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<int> rmn(m, numeric_limits<int>::max());
        vector<int> cmx(n, numeric_limits<int>::min());
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rmn[i] = min(rmn[i], matrix[i][j]);
                cmx[j] = max(cmx[j], matrix[i][j]);
            }
        }

        vector<int> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (int v = matrix[i][j]; v == rmn[i] && v == cmx[j]) {
                    result.push_back(v);
                }
            }
        }

        return result;
    }
};
