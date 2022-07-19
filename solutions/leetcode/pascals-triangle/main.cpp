class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};
        for (int i = 1; i < numRows; ++i) {
            result.push_back(vector<int>(i + 1, 0));
            for (int j = 0; j < i + 1; ++j) {
                if (j > 0) result[i][j] += result[i - 1][j - 1];
                if (j < i) result[i][j] += result[i - 1][j];
            }
        }
        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};
        for (int i = 2; i <= numRows; ++i) {
            result.push_back({});
            for (int j = 0; j < i; ++j) {
                int v = 0;
                if (j - 1 >= 0) v += result[i - 2][j - 1];
                if (j < i - 1) v += result[i - 2][j];
                result.back().push_back(v);
            }
        }
        return result;
    }
};
