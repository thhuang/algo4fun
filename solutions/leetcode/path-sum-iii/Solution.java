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
    private HashMap<Long, Integer> prefix;
    private int target;

    private void dfs(TreeNode u, long sum) {
        if (u == null) {
            return;
        }
        sum += u.val;
        result += prefix.getOrDefault(sum - target, 0);
        prefix.put(sum, prefix.getOrDefault(sum, 0) + 1);
        dfs(u.left, sum);
        dfs(u.right, sum);
        prefix.put(sum, prefix.getOrDefault(sum, 0) - 1);
    }

    public int pathSum(TreeNode root, int targetSum) {
        target = targetSum;
        result = 0;
        prefix = new HashMap<Long, Integer>();
        prefix.put(0L, 1);
        dfs(root, 0L);
        return result;
    }
}
