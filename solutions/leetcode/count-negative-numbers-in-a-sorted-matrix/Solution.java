class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int result = 0;
        for (int i = 0, j = n - 1; i < m; ++i) {
            while (j >= 0 && grid[i][j] < 0) {
                --j;
            }
            result += n - j - 1;
        }

        return result;
    }
}
