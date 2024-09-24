class Trie {
    class Node {
        Node[] children = new Node[10];
    }

    private Node root = new Node();

    public void insert(int num) {
        String s = Integer.toString(num);
        Node p = root;

        for (char c : s.toCharArray()) {
            int i = c - '0';
            if (p.children[i] == null) {
                p.children[i] = new Node();
            }
            p = p.children[i];
        }
    }

    public int getLongestPrefixLength(int num) {
        String s = Integer.toString(num);
        Node p = root;

        int result = 0;
        for (char c : s.toCharArray()) {
            int i = c - '0';
            if (p.children[i] == null) {
                break;
            }
            p = p.children[i];
            ++result;
        }

        return result;
    }
}

class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Trie trie = new Trie();

        for (int v : arr1) {
            trie.insert(v);
        }

        int result = 0;
        for (int v : arr2) {
            result = Math.max(result, trie.getLongestPrefixLength(v));
        }

        return result;
    }
}