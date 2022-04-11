class Solution {
   public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid.front().size();
        int N = n * m;
        k %= N;

        auto get_coord = [&](int i) -> array<int, 2> { return {i / m, i % m}; };

        for (int i = 0; i < N / 2; ++i) {
            auto [r0, c0] = get_coord(i);
            auto [r1, c1] = get_coord(N - 1 - i);
            swap(grid[r0][c0], grid[r1][c1]);
        }

        for (int i = 0; i < k / 2; ++i) {
            auto [r0, c0] = get_coord(i);
            auto [r1, c1] = get_coord(k - 1 - i);
            swap(grid[r0][c0], grid[r1][c1]);
        }

        for (int i = 0; i < (N - k) / 2; ++i) {
            auto [r0, c0] = get_coord(k + i);
            auto [r1, c1] = get_coord(N - 1 - i);
            swap(grid[r0][c0], grid[r1][c1]);
        }

        return grid;
    }
};
