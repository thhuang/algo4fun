class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder result = new StringBuilder();

        int mn = Math.min(word1.length(), word2.length());
        for (int i = 0; i < mn; ++i) {
            result.append(word1.charAt(i));
            result.append(word2.charAt(i));
        }

        String word = word1.length() > word2.length() ? word1 : word2;
        for (int i = mn; i < word.length(); ++i) {
            result.append(word.charAt(i));
        }

        return result.toString();
    }
}
