class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        for (int i = 0, j = n - 1; i < m && j >= 0;
             (matrix[i][j] < target) ? ++i : --j) {
            if (matrix[i][j] == target) return true;
        }

        return false;
    }
};
