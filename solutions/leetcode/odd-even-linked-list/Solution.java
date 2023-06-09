/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        var odd = new ListNode();
        var even = new ListNode();
        ListNode o = odd, e = even;
        var p = o;
        for (int i = 1; head != null; ++i, head = head.next) {
            p.next = head;
            if (i % 2 == 0) {
                e = e.next;
                p = o;
            } else {
                o = o.next;
                p = e;
            }
        }
        p.next = null;
        o.next = even.next;
        return odd.next;
    }
}
