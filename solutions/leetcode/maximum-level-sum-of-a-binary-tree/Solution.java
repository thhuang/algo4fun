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
    public int maxLevelSum(TreeNode root) {
        int result = 0;
        int mx = Integer.MIN_VALUE;
        ArrayList<TreeNode> q = new ArrayList<TreeNode>();
        q.add(root);
        for (int i = 1; !q.isEmpty(); ++i) {
            int v = 0;
            ArrayList<TreeNode> qNew = new ArrayList<TreeNode>();
            for (var u : q) {
                v += u.val;
                if (u.left != null) {
                    qNew.add(u.left);
                }
                if (u.right != null) {
                    qNew.add(u.right);
                }
            }
            if (v > mx) {
                mx = v;
                result = i;
            }
            q = qNew;
        }
        return result;
    }
}
