/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import "math"

func maxLevelSum(root *TreeNode) int {
	result := 0
	mx := math.MinInt32

	q := []*TreeNode{root}
	for i := 1; len(q) > 0; i++ {
		sum := 0
		n := len(q)

		for j := 0; j < n; j++ {
			u := q[0]
			q = q[1:]

			sum += u.Val
			if u.Left != nil {
				q = append(q, u.Left)
			}
			if u.Right != nil {
				q = append(q, u.Right)
			}
		}

		if sum > mx {
			result = i
			mx = sum
		}
	}

	return result
}
