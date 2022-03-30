class Solution {
   public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        int dx = x - coordinates[1][0];
        int dy = y - coordinates[1][1];
        for (int i = 0; i < coordinates.size(); ++i) {
            if (dx * (y - coordinates[i][1]) != dy * (x - coordinates[i][0]))
                return false;
        }
        return true;
    }
};
