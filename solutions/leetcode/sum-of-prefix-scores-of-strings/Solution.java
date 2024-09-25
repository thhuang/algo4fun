class Solution {
    class Trie {
        class Node {
            int score = 0;
            Node[] children = new Node[26];
        }

        private Node root;

        public Trie() {
            root = new Node();
        }

        public void insert(String s) {
            Node p = root;
            for (char c : s.toCharArray()) {
                int i = c - 'a';
                if (p.children[i] == null) {
                    p.children[i] = new Node();
                }
                p = p.children[i];
                ++p.score;
            }
        }

        public int getScore(String s) {
            int result = 0;
            Node p = root;
            for (char c : s.toCharArray()) {
                int i = c - 'a';
                p = p.children[i];
                result += p.score;
            }
            return result;
        }
    }

    public int[] sumPrefixScores(String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        int[] result = new int[words.length];
        for (int i = 0; i < words.length; ++i) {
            result[i] = trie.getScore(words[i]);
        }
        return result;
    }
}
