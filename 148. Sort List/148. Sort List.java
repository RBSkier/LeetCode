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
class Solution {                                                                                             private ListNode merge(ListNode l, ListNode r) {
        ListNode dummy = new ListNode(-1), curr;
        for(curr = dummy; l != null && r != null; curr = curr.next){
            if(l.val <= r.val){
                curr.next = l;
                l = l.next;
            }else{
                curr.next = r;
                r = r.next;
            }
        }
        //append the rest of list1 or list2 to meger list.
        curr.next = l != null ? l : r;

        return dummy.next;
    }
    public ListNode sortList(ListNode head) {
        //get the list sz.
        int N = 0;
        for(var curr = head; curr != null; curr = curr.next) N++;
        
        var dummy = new ListNode(-1, head);
        //sz: sublist size.
        for(int sz = 1; sz < N; sz = sz+sz){
            ListNode pre = dummy, curr = dummy.next, next;
            for(int lo = 0; lo < N-sz; lo += sz+sz){
                //crop out the left linked list from origin list.
                var l = curr;
                for(int i = 1; i < sz; i++) curr = curr.next; //curr move sz step.
                var r = curr.next;
                curr.next = null;
                //crop out the right linked list from origin list.
                curr = r;
                for(int i = 1; i < Math.min(sz, N-(lo+sz)); i++) curr = curr.next; //the rest of list may smaller than sz.
                next = curr.next;  //record for later use.
                curr.next = null;
                //merge l and r and then link back to main list.
                pre.next = merge(l, r);
                while(pre.next != null) pre = pre.next;
                pre.next = next;
                //move curr to the remaining unprocessed list.
                curr = next;
            }
        }
        return dummy.next;
    }
}
