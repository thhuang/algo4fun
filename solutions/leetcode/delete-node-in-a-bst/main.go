/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}
	if key < root.Val {
		root.Left = deleteNode(root.Left, key)
		return root
	}
	if key > root.Val {
		root.Right = deleteNode(root.Right, key)
		return root
	}
	if root.Right == nil {
		return root.Left
	}

	u := root.Right
	for u.Left != nil {
		u = u.Left
	}
	root.Right = deleteNode(root.Right, u.Val)
	u.Left, u.Right = root.Left, root.Right
	return u
}
