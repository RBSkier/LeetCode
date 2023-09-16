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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null)
            return null;

        ListNode head = null, tail = null;
        int carry = 0;

        while(l1 != null || l2 != null){
            int digit1 = (l1 != null) ? l1.val: 0;
            int digit2 = (l2 != null) ? l2.val: 0;
            int sum = digit1 + digit2 + carry;

            if(head == null)
                head = tail = new ListNode(sum % 10);  //插入结点
            else{
                tail.next =  new ListNode(sum % 10);  //插入结点
                tail = tail.next;
            }

            carry = sum / 10;
            l1 = (l1 != null)? l1.next: null;
            l2 = (l2 != null)? l2.next: null;
        }
        if(carry != 0)
            tail.next =  new ListNode(carry);

        return head;
    }
}
