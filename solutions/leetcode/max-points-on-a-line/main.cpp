class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int result = 1;
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dx0 = points[i][0] - points[j][0];
                int dy0 = points[i][1] - points[j][1];
                int count = 2;
                for (int k = j + 1; k < n; ++k) {
                    int dx1 = points[i][0] - points[k][0];
                    int dy1 = points[i][1] - points[k][1];
                    if (dy0 * dx1 == dy1 * dx0) ++count;
                }
                result = max(result, count);
            }
        }

        return result;
    }
};
