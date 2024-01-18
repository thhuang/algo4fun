/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	odd := &ListNode{}
	even := &ListNode{}
	oddPrev := odd
	evenPrev := even

	for i := 1; head != nil; i++ {
		if i%2 == 1 {
			odd.Next = head
			odd = odd.Next
		} else {
			even.Next = head
			even = even.Next
		}
		head = head.Next
	}

	even.Next = nil
	odd.Next = evenPrev.Next

	return oddPrev.Next
}
