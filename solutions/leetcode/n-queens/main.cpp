class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> col(n, false), diag0(n * 2 - 1, false),
            diag1(n * 2 - 1, false);

        vector<string> state;
        function<void(int)> search = [&](int i) -> void {
            if (i == n) {
                result.push_back(state);
                return;
            }

            string rol(n, '.');
            for (int j = 0; j < n; ++j) {
                if (col[j]) continue;
                if (diag0[i + j]) continue;
                if (diag1[i - j + n - 1]) continue;

                col[j] = diag0[i + j] = diag1[i - j + n - 1] = true;
                rol[j] = 'Q';
                state.push_back(rol);

                search(i + 1);

                state.pop_back();
                rol[j] = '.';
                col[j] = diag0[i + j] = diag1[i - j + n - 1] = false;
            }
        };

        search(0);

        return result;
    }
};
