class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> curr, prev = {triangle[0][0]};
        for (int i = 1; i < triangle.size(); ++i) {
            curr.assign(i + 1, numeric_limits<int>::max());
            for (int j = 0; j < curr.size(); ++j) {
                if (j > 0) curr[j] = min(curr[j], prev[j - 1]);
                if (j < i) curr[j] = min(curr[j], prev[j]);
                curr[j] += triangle[i][j];
            }
            prev = move(curr);
        }
        return *min_element(prev.begin(), prev.end());
    }
};
