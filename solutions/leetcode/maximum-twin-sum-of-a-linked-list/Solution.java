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
    private ListNode reverse(ListNode head) {
        ListNode a = null;
        ListNode b = head;
        while (b != null) {
            ListNode c = b.next;
            b.next = a;
            a = b;
            b = c;
        }
        return a;
    }

    public int pairSum(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode slow = dummy;
        ListNode fast = dummy;
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode r = slow.next;
        slow.next = null;
        ListNode l = reverse(head);

        int result = 0;
        while (r != null) {
            result = Math.max(result, l.val + r.val);
            l = l.next;
            r = r.next;
        }
        return result;
    }
}
