class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = size(matrix);
        int m = size(matrix[0]);
        int l = 0, r = n * m - 1;

        auto coord = [&](int v) -> array<int, 2> { return {v / m, v % m}; };

        while (l <= r) {
            int mid = l + (r - l) / 2;
            auto [i, j] = coord(mid);
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
