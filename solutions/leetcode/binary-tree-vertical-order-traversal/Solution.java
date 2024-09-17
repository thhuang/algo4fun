/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public List<List<Integer>> verticalOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        Map<Integer, List<Integer>> colToVals = new HashMap<>();
        Queue<Pair<TreeNode, Integer>> q = new ArrayDeque<>();
        q.offer(new Pair<>(root, 0));

        int min = 0;
        int max = 0;

        while (!q.isEmpty()) {
            Pair<TreeNode, Integer> p = q.poll();
            TreeNode u = p.getKey();
            Integer col = p.getValue();

            colToVals.putIfAbsent(col, new ArrayList<Integer>());
            colToVals.get(col).add(u.val);

            min = Math.min(min, col);
            max = Math.max(max, col);

            if (u.left != null) {
                q.offer(new Pair(u.left, col - 1));
            }
            if (u.right != null) {
                q.offer(new Pair(u.right, col + 1));
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = min; i <= max; ++i) {
            result.add(colToVals.get(i));
        }

        return result;
    }
}