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
    public ListNode reverseKGroup(ListNode head, int k) {
        int n = 0;
        for (ListNode cur = head; cur != null; cur = cur.next)
            ++n; // count the length of list.

        ListNode dummy = new ListNode(0, head), p0 = dummy;
        ListNode pre = null, cur = head;
        for (; n >= k; n -= k) {
            for (int i = 0; i < k; ++i) { //the same as question 206.
                ListNode next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = next;
            }

            ListNode temp = p0.next; //record the new segment tail.
            p0.next = pre; //p0 change to link the new segment head.
            p0 = temp; //update p0 from old segment tail to new segment tail.
            
            p0.next = cur; //link the new segment tail to the rest list.
        }
        return dummy.next;
    }
}
