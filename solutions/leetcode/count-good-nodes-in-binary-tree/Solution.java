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
    private int dfs(TreeNode u, int mx) {
        if (u == null)
            return 0;
        int result = 0;
        if (u.val >= mx)
            ++result;
        mx = Math.max(mx, u.val);
        result += dfs(u.left, mx) + dfs(u.right, mx);
        return result;
    }

    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
}
