/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestZigZag(root *TreeNode) int {
	result := 0

	var dfs func(*TreeNode, bool, int)
	dfs = func(u *TreeNode, goLeft bool, path int) {
		if u == nil {
			return
		}

		result = max(result, path)

		if goLeft {
			dfs(u.Left, false, path+1)
			dfs(u.Right, true, 1)
		} else {
			dfs(u.Left, false, 1)
			dfs(u.Right, true, path+1)
		}
	}

	dfs(root, true, 0)
	dfs(root, false, 0)

	return result
}

func longestZigZag(root *TreeNode) int {
	result := 0

	var dfs func(*TreeNode, bool) int
	dfs = func(u *TreeNode, isLeft bool) int {
		if u == nil {
			return 0
		}

		l := dfs(u.Left, true)
		r := dfs(u.Right, false)

		result = max(result, max(l, r))

		if isLeft {
			return r + 1
		}
		return l + 1
	}

	dfs(root, true)

	return result
}
