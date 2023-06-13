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
    private int result;
    private enum Direction { Left, Right };

    private int dfs(TreeNode u, Direction d) {
        if (u == null) {
            return 0;
        }
        int l = dfs(u.left, Direction.Left);
        int r = dfs(u.right, Direction.Right);
        result = Math.max(result, Math.max(l, r));
        return d == Direction.Left ? r + 1 : l + 1;
    }

    public int longestZigZag(TreeNode root) {
        result = 0;
        dfs(root, Direction.Left);
        return result;
    }
}
