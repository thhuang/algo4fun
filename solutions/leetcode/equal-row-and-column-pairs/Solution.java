class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;

        HashMap<String, Integer> row = new HashMap<String, Integer>();
        for (int i = 0; i < n; ++i) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; ++j) {
                sb.append(grid[i][j]);
                sb.append(' ');
            }
            String s = sb.toString();
            row.put(s, row.getOrDefault(s, 0) + 1);
        }

        HashMap<String, Integer> col = new HashMap<String, Integer>();
        for (int j = 0; j < n; ++j) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; ++i) {
                sb.append(grid[i][j]);
                sb.append(' ');
            }
            String s = sb.toString();
            col.put(s, col.getOrDefault(s, 0) + 1);
        }

        int result = 0;
        for (Map.Entry<String, Integer> kv : row.entrySet()) {
            String s = kv.getKey();
            Integer v = kv.getValue();
            result += col.getOrDefault(s, 0) * v;
        }

        return result;
    }
}
