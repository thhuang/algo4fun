class Solution {
   public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = size(piles);
        vector<vector<int>> mem(n, vector<int>(k + 1, -1));
        function<int(int, int)> search = [&](int i, int j) -> int {
            if (i == n) return 0;
            if (~mem[i][j]) return mem[i][j];

            int value = search(i + 1, j);
            int sum = 0;
            for (int t = 0; t < j && t < size(piles[i]); ++t) {
                sum += piles[i][t];
                value = max(value, search(i + 1, j - t - 1) + sum);
            }

            return mem[i][j] = value;
        };
        return search(0, k);
    }
};
