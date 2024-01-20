/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import "math"

func goodNodes(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(u *TreeNode, mx int) int {
		if u == nil {
			return 0
		}

		mx = max(mx, u.Val)

		result := 0
		if u.Val >= mx {
			result++
		}

		result += dfs(u.Left, mx)
		result += dfs(u.Right, mx)

		return result
	}

	return dfs(root, math.MinInt32)
}
