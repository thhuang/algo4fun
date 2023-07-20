class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        int l = 0, r = rows * cols - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int i = m / cols;
            int j = m % cols;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
};

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        int l = 0, r = m * n - 1;
        while (l <= r) {
            int i = l + (r - l) / 2;
            int v = matrix[i / n][i % n];
            if (v == target) return true;
            v < target ? l = i + 1 : r = i - 1;
        }

        return false;
    }
};
