/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun verticalOrder(root: TreeNode?): List<List<Int>> {
        if (root == null) {
            return emptyList()
        }

        val colToVals: MutableMap<Int, MutableList<Int>> = mutableMapOf()
        val q: Queue<Pair<TreeNode, Int>> = LinkedList()
        q.offer(Pair(root, 0))

        var min = 0
        var max = 0

        while (q.isNotEmpty()) {
            val (u, col) = q.poll()

            colToVals.putIfAbsent(col, mutableListOf())
            colToVals[col]?.add(u.`val`)

            min = minOf(min, col)
            max = maxOf(max, col)

            u.left?.let {
                q.add(it to col - 1)
            }
            u.right?.let {
                q.add(it to col + 1)
            }
        }

        val result: MutableList<List<Int>> = mutableListOf()
        for (i in min..max) {
            result.add(colToVals[i]!!)
        }

        return result
    }
}