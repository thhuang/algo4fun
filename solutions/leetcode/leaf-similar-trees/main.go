/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {

	collect = func(u *TreeNode, leaves *[]int) {
		if u.Left == nil && u.Right == nil {
			*leaves = append(*leaves, u.Val)
			return
		}
		if u.Left != nil {
			collect(u.Left, leaves)
		}
		if u.Right != nil {
			collect(u.Right, leaves)
		}
	}

	leaves1 := []int{}
	collect(root1, &leaves1)

	leaves2 := []int{}
	collect(root2, &leaves2)

	if len(leaves1) != len(leaves2) {
		return false
	}

	for i := range leaves1 {
		if leaves1[i] != leaves2[i] {
			return false
		}
	}
	return true
}
