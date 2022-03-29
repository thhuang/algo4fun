class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};
        for (int i = 1; i < numRows; ++i) {
            result.push_back(vector<int>(i + 1));
            for (int j = 0; j < result.back().size(); ++j) {
                int a = j > 0 ? result[i - 1][j - 1] : 0;
                int b = j < result[i - 1].size() ? result[i - 1][j] : 0;
                result[i][j] = a + b;
            }
        }
        return result;
    }
};
