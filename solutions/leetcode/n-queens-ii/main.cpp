class Solution {
   public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> col(n, false), diag0(n * 2 - 1, false), diag1(n * 2 - 1, false);

        function<void(int)> search = [&](int i) -> void {
            if (i == n) {
                ++count;
                return;
            }

            for (int j = 0; j < n; ++j) {
                if (col[j] || diag0[i + j] || diag1[i - j + n - 1]) continue;

                col[j] = diag0[i + j] = diag1[i - j + n - 1] = true;
                search(i + 1);
                col[j] = diag0[i + j] = diag1[i - j + n - 1] = false;
            }
        };

        search(0);

        return count;
    }
};
