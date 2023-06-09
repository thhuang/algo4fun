class Solution {
    int p;

    public String decodeString(String s) {
        p = 0;
        return decode(s.toCharArray());
    }

    private String decode(char[] s) {
        var sb = new StringBuilder();
        for (; p < s.length && s[p] != ']'; ++p) {
            if (!Character.isDigit(s[p])) {
                sb.append(s[p]);
                continue;
            }

            int v = 0;
            for (; s[p] != '['; ++p) {
                v = v * 10 + Character.getNumericValue(s[p]);
            }
            ++p;
            String sub = decode(s);
            for (int i = 0; i < v; ++i) {
                sb.append(sub);
            }
        }
        return sb.toString();
    }
}
