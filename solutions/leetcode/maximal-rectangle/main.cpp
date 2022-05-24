class Solution {
   public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        int result = 0;
        vector<int> height(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    ++height[j];
                }
            }

            vector<int> height_index;
            for (int j = 0; j <= n; ++j) {
                while (!height_index.empty() &&
                       (j == n || height[height_index.back()] >= height[j])) {
                    int idx = height_index.back();
                    height_index.pop_back();

                    int h = height[idx];
                    int w = j;
                    if (!height_index.empty()) w = j - height_index.back() - 1;
                    result = max(result, h * w);
                }

                height_index.push_back(j);
            }
        }

        return result;
    }
};
