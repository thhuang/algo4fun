class Solution {
    private static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    private static void swap(char[] cs, int i, int j) {
        char tmp = cs[i];
        cs[i] = cs[j];
        cs[j] = tmp;
    }

    public String reverseVowels(String s) {
        char[] cs = s.toCharArray();

        int l = 0, r = cs.length - 1;
        while (l < r) {
            while (l < r && !isVowel(cs[l])) {
                ++l;
            }
            while (l < r && !isVowel(cs[r])) {
                --r;
            }
            swap(cs, l++, r--);
        }

        return new String(cs);
    }
}
