/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        Stack<Pair<TreeNode, Integer>> stack = new Stack<Pair<TreeNode, Integer>>();
        stack.add(new Pair(root, 0));
        while (!stack.empty()) {
            var entry = stack.pop();
            var u = entry.getKey();
            var d = entry.getValue();
            if (u == null) {
                continue;
            }
            if (d == result.size()) {
                result.add(u.val);
            }
            stack.add(new Pair(u.left, d + 1));
            stack.add(new Pair(u.right, d + 1));
        }
        return result;
    }
}
