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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy= new ListNode(-1);
        ListNode p1 = dummy, p2 = dummy;
        dummy.next = head;
        for (int i = 0; i < n; i++){
            p1 = p1.next;
        }
        while(p1.next != null){
            p1 = p1.next;
            p2 = p2.next;
        }
        // p2.next is last n th node
        p2.next = p2.next.next;
        return dummy.next;
    }
}
