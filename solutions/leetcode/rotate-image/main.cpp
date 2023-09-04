class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n / 2; ++j)
                swap(matrix[i][j], matrix[i][n - j - 1]);
    }
};

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (auto& row : matrix)
            reverse(row.begin(), row.end());
    }
};

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            for (int l = 0, r = n - 1; l < r; ++l, --r) {
                swap(matrix[i][l], matrix[i][r]);
            }
        }
    }
};
