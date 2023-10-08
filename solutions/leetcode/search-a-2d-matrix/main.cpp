class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        int l = 0, r = m * n - 1;
        while (l <= r) {
            int p = l + (r - l) / 2;
            int i = p / n, j = p % n;
            if (matrix[i][j] <= target) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }

        if (r >= 0 && matrix[r / n][r % n] == target) return true;
        return false;
    }
};

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix.front().size();

        int l = 0, r = rows * cols;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (target < matrix[m / cols][m % cols]) {
                r = m;
            } else {
                l = m;
            }
        }

        return matrix[l / cols][l % cols] == target;
    }
};
