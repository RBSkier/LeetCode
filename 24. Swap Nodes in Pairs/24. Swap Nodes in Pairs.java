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
    public ListNode swapPairs(ListNode head) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode curr = dummyHead;
        while(curr.next != null && curr.next.next != null){
            ListNode node1 = curr.next;
            ListNode node2 = curr.next.next;
            //relink the new sub head.
            curr.next = node2;
            node1.next = node2.next;
            node2.next = node1;
            curr = node1;
        }
        return dummyHead.next;
    }
}


