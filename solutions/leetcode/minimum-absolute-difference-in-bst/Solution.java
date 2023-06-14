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
    int p;
    int result;

    private void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        result = Math.min(result, root.val - p);
        p = root.val;
        inorder(root.right);
    }

    public int getMinimumDifference(TreeNode root) {
        result = (int)1e5;
        p = (int)-1e5;
        inorder(root);
        return result;
    }
}
