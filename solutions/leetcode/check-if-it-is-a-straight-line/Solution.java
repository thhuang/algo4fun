class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int x = coordinates[0][0], y = coordinates[0][1];
        int dx = coordinates[1][0] - x, dy = coordinates[1][1] - y;
        for (int[] v : coordinates) {
            int di = v[0] - x, dj = v[1] - y;
            if (dx * dj != di * dy) {
                return false;
            }
        }
        return true;
    }
}
