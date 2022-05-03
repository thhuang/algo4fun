class Solution {
   public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> min_cost_cache(
            n, vector<int>(n, numeric_limits<int>::max()));
        vector<vector<int>> max_val_cache(
            n, vector<int>(n, numeric_limits<int>::min()));

        function<void(int, int)> search = [&](int l, int r) -> void {
            if (max_val_cache[l][r] >= 0) return;
            if (l == r) {
                min_cost_cache[l][r] = 0;
                max_val_cache[l][r] = arr[l];
                return;
            }

            for (int i = l; i < r; ++i) {
                search(l, i);
                search(i + 1, r);
                int min_cost = min_cost_cache[l][i] + min_cost_cache[i + 1][r] +
                               max_val_cache[l][i] * max_val_cache[i + 1][r];
                int max_val = max(max_val_cache[l][i], max_val_cache[i + 1][r]);
                if (min_cost < min_cost_cache[l][r]) {
                    min_cost_cache[l][r] = min_cost;
                    max_val_cache[l][r] = max_val;
                }
            }
        };

        search(0, n - 1);

        return min_cost_cache[0][n - 1];
    }
};
