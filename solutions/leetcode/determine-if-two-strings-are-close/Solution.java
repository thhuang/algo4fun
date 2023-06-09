class Solution {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false;
        }

        HashMap<Character, Integer> charCount1 = new HashMap<Character, Integer>();
        HashMap<Character, Integer> charCount2 = new HashMap<Character, Integer>();
        HashSet<Character> chars1 = new HashSet<Character>();
        HashSet<Character> chars2 = new HashSet<Character>();
        for (char c : word1.toCharArray()) {
            charCount1.put(c, charCount1.getOrDefault(c, 0) + 1);
            chars1.add(c);
        }
        for (char c : word2.toCharArray()) {
            charCount2.put(c, charCount2.getOrDefault(c, 0) + 1);
            chars2.add(c);
        }

        if (chars1.size() != chars2.size()) {
            return false;
        }
        for (char c : chars1) {
            if (!chars2.contains(c)) {
                return false;
            }
        }

        HashMap<Integer, Integer> countChar1 = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> countChar2 = new HashMap<Integer, Integer>();
        for (Map.Entry<Character, Integer> kv : charCount1.entrySet()) {
            int cnt = kv.getValue();
            countChar1.put(cnt, countChar1.getOrDefault(cnt, 0) + 1);
        }
        for (Map.Entry<Character, Integer> kv : charCount2.entrySet()) {
            int cnt = kv.getValue();
            countChar2.put(cnt, countChar2.getOrDefault(cnt, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> kv : countChar1.entrySet()) {
            if (countChar2.getOrDefault(kv.getKey(), 0) != kv.getValue()) {
                return false;
            }
        }

        return true;
    }
}
