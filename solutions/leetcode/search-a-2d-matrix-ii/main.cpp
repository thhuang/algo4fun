class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix.front().size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (target == matrix[i][j]) return true;
            if (target < matrix[i][j]) {
                --j;
            } else {  // target > matrix[i][j]
                ++i;
            }
        }
        return false;
    }
};
