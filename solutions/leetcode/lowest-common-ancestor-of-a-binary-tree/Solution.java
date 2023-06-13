/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if (root == p || root == q) return root;
        var l = lowestCommonAncestor(root.left, p, q);
        var r = lowestCommonAncestor(root.right, p, q);
        if (l == null) return r;
        if (r == null) return l;
        return root;
    }
}
