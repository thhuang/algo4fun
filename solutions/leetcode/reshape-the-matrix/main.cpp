class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();

        if (n * m != r * c) return mat;

        vector<vector<int>> result(r, vector<int>(c));
        for (int i = 0; i < n * m; ++i) {
            int x0 = i / m, y0 = i % m;
            int x1 = i / c, y1 = i % c;
            result[x1][y1] = mat[x0][y0];
        }

        return result;
    }
};
}
}
}
