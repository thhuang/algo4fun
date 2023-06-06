class Solution {
    private static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public int maxVowels(String s, int k) {
        int curr = 0;
        for (int i = 0; i < k - 1; ++i) {
            if (isVowel(s.charAt(i))) {
                ++curr;
            }
        }

        int result = curr;
        for (int i = k - 1; i < s.length(); ++i) {
            if (isVowel(s.charAt(i))) {
                result = Math.max(result, ++curr);
            }
            if (isVowel(s.charAt(i - k + 1))) {
                --curr;
            }
        }

        return result;
    }
}

class Solution {
    private static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public int maxVowels(String s, int k) {
        int curr = 0;
        for (int i = 0; i < k - 1; ++i) {
            if (isVowel(s.charAt(i))) {
                ++curr;
            }
        }

        int result = 0;
        for (int i = k - 1; i < s.length(); ++i) {
            if (isVowel(s.charAt(i))) {
                ++curr;
            }
            result = Math.max(result, curr);
            if (isVowel(s.charAt(i - k + 1))) {
                --curr;
            }
        }

        return result;
    }
}
