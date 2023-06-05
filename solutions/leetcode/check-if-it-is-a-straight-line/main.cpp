class Solution {
   public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x = coordinates[0][0], y = coordinates[0][1];
        int dx = coordinates[1][0] - x, dy = coordinates[1][1] - y;
        for (vector<int>& v : coordinates) {
            int di = x - v[0], dj = y - v[1];
            if (dx * dj != dy * di) return false;
        }
        return true;
    }
};
