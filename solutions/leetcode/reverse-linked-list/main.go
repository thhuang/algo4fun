/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	var a *ListNode = nil
	b := head
	for b != nil {
		c := b.Next
		b.Next = a
		a, b = b, c
	}
	return a
}
