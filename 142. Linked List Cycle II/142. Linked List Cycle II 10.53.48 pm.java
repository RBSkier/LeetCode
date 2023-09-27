/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head, slow = head;
        while(true){
            if(fast == null || fast.next == null)    return null;
            slow = slow.next;
            fast = fast.next.next;
            if(fast == slow)    break;
        }
        //from the meetion of fast and slow to the meetion of slow and ptr3.
        ListNode ptr3 = head;
        while(ptr3 != slow){
            ptr3 = ptr3.next;
            slow = slow.next;
        }
        return slow;
    }
}
