class Solution {
    static private int gcd(int a, int b) {
        if (a % b == 0)
            return b;
        return gcd(b, a % b);
    }

    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1))
            return "";
        int m = str1.length();
        int n = str2.length();
        int v = m > n ? gcd(m, n) : gcd(n, m);
        return str1.substring(0, v);
    }
}
