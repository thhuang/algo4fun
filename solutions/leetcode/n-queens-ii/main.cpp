class Solution {
   public:
    int totalNQueens(int n) {
        vector<bool> col(n), ldiag(n * 2 - 1), rdiag(n * 2 - 1);

        int result = 0;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ++result;
                return;
            }

            for (int j = 0; j < n; ++j) {
                if (col[j] || ldiag[i + j] || rdiag[j - i + n - 1]) continue;
                col[j] = ldiag[i + j] = rdiag[j - i + n - 1] = true;
                dfs(i + 1);
                col[j] = ldiag[i + j] = rdiag[j - i + n - 1] = false;
            }
        };

        dfs(0);

        return result;
    }
};
