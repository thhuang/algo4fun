class Solution {
   public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_map<int, unordered_set<int>> points;
        int count = 0;
        for (auto p : circles) {
            int x = p[0], y = p[1], r = p[2];
            for (int i = x - r; i <= x + r; ++i) {
                for (int j = y - r; j <= y + r; ++j) {
                    if (points[i].count(j)) continue;
                    int dx = x - i;
                    int dy = y - j;
                    if (dx * dx + dy * dy <= r * r) {
                        ++count;
                        points[i].insert(j);
                    }
                }
            }
        }
        return count;
    }
};
