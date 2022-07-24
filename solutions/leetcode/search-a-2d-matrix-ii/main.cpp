class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            const int& v = matrix[i][j];
            if (v == target) return true;
            if (v < target)
                ++i;
            else  // v > target
                --j;
        }
        return false;
    }
};
