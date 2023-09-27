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
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        ListNode curr1 = head, curr2 = head.next;
        while(curr1 != null && curr2 != null && curr2.next != null) {
            curr1 = curr1.next;
            curr2 = curr2.next.next;
            //if curr2 reaches curr1 or passes curr1.
            if(curr2 == curr1)  return true;
        }
        return false;
    }
}