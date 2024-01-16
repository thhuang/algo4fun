/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	dummy := &ListNode{0, head}

	p := dummy
	u := head

	for u != nil {
		r := u

		lenLessThanK := false
		for i := 0; i < k-1; i++ {
			if r.Next == nil {
				lenLessThanK = true
				break
			}
			r = r.Next
		}

		if lenLessThanK {
			break
		}

		q := r
		r = r.Next
		q.Next = nil

		l := reverse(u)

		p.Next, u.Next = l, r
		p, u = u, r
	}

	return dummy.Next
}

func reverse(head *ListNode) *ListNode {
	var a *ListNode
	b := head
	for b != nil {
		c := b.Next
		b.Next = a
		a, b = b, c
	}
	return a
}
