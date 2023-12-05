class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        List<StringBuilder> rows = new ArrayList<StringBuilder>();
        for (int i = 0; i < numRows; ++i) {
            rows.add(new StringBuilder());
        }

        for (int i = 0, r = 0, dir = 1; i < s.length(); ++i, r += dir) {
            rows.get(r).append(s.charAt(i));
            if (r + dir < 0 || r + dir == rows.size()) {
                dir = -dir;
            }
        }

        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }

        return result.toString();
    }
}
