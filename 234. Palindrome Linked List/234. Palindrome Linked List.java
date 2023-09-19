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
    public boolean isPalindrome(ListNode head) {
        if(head == null)   return true;
        ListNode firstHalfEnd = getMiddleNode(head);
        ListNode secondHalfStart = reverseList(firstHalfEnd.next);

        while(secondHalfStart != null){
            if(head.val != secondHalfStart.val) return false;
            head = head.next;
            secondHalfStart = secondHalfStart.next;
        }
        return true;
    }

    private ListNode getMiddleNode(ListNode head){
        ListNode fast = head, slow = head;
        while(fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    private ListNode reverseList(ListNode halfHead){
        ListNode pre = null, cur = halfHead;
        while(cur != null){
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
}
