class Solution {
   public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_dist = numeric_limits<int>::max();
        int result = -1;
        for (int i = 0; i < size(points); ++i) {
            const auto& p = points[i];
            if (p[0] != x && p[1] != y) continue;
            if (int d = abs(p[0] - x) + abs(p[1] - y); d < min_dist) {
                min_dist = d;
                result = i;
            }
        }
        return result;
    }
};
