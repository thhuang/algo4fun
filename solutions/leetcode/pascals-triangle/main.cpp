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
        vector<vector<int>> result(numRows, {1});
        for (int i = 1; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) {
                result[i].push_back(result[i - 1][j] + result[i - 1][j - 1]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};
