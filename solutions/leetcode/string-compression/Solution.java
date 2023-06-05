class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        int p = 0;
        for (int l = 0; l < n;) {
            int r = l + 1;
            while (r < n && chars[l] == chars[r]) {
                ++r;
            }

            int d = r - l;
            chars[p++] = chars[l];
            l = r;

            if (d == 1) {
                continue;
            }
            for (char c : String.valueOf(d).toCharArray()) {
                chars[p++] = c;
            }
        }
        return p;
    }
}
