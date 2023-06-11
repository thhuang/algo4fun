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
    private void collect(TreeNode u, List<Integer> leaves) {
        if (u.left == null && u.right == null) {
            leaves.add(u.val);
            return;
        }
        if (u.left != null) {
            collect(u.left, leaves);
        }
        if (u.right != null) {
            collect(u.right, leaves);
        }
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leaves1 = new ArrayList<Integer>();
        List<Integer> leaves2 = new ArrayList<Integer>();
        collect(root1, leaves1);
        collect(root2, leaves2);
        return leaves1.equals(leaves2);
    }
}
