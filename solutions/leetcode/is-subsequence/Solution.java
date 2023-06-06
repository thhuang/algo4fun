class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() == 0) {
            return true;
        }

        int m = s.length(), n = t.length();
        for (int i = 0, j = 0; j < n; ++j) {
            if (s.charAt(i) == t.charAt(j)) {
                ++i;
                if (i == m) {
                    return true;
                }
            }
        }
        return false;
    }
}
