class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        StringBuilder result = new StringBuilder();
        for (int i = words.length - 1; i >= 0; --i) {
            if (words[i].isEmpty()) {
                continue;
            }
            result.append(words[i] + " ");
        }
        return result.substring(0, result.length() - 1);
    }
}

