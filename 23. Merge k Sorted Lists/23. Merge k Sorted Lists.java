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
    public ListNode mergeKLists(ListNode[] lists) {
        int N = lists.length;
        if(N == 0) return null;

        for(int sz = 1; sz < N; sz = sz+sz) //sz: subarray size.
            for(int lo = 0; lo+sz < N; lo += sz+sz)
                lists[lo] = merge(lists[lo], lists[lo+sz]); //reuse the lists to store merge result.
        return lists[0];
    }

    private ListNode merge(ListNode l, ListNode r){
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
        curr.next = l != null ? l : r;
        return dummy.next;
    }
}
