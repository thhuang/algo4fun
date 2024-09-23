class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();

        int[] dp = new int[n + 1];
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1;
            for (String w : dictionary) {
                int len = w.length();
                if (i + len <= n && s.substring(i, i + len).equals(w)) {
                    dp[i] = Math.min(dp[i], dp[i + len]);
                }
            }
        }

        return dp[0];
    }
}