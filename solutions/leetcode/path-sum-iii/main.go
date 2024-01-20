/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, targetSum int) int {
	result := 0

	prefix := map[int]int{0: 1}
	sum := 0

	var dfs func(*TreeNode)
	dfs = func(u *TreeNode) {
		if u == nil {
			return
		}
		sum += u.Val
		result += prefix[sum-targetSum]
		prefix[sum]++
		dfs(u.Left)
		dfs(u.Right)
		prefix[sum]--
		sum -= u.Val
	}

	dfs(root)

	return result
}
