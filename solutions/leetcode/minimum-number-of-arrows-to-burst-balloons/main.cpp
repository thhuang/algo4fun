class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1]) return a[0] < b[0];
                 return a[1] < b[1];
             });

        int count = 0;
        int i = 0;
        while (i < points.size()) {
            ++count;

            int x = points[i][1];
            while (i < points.size() && points[i][0] <= x) ++i;
        }

        return count;
    }
};
