/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
//stack
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Deque<ListNode> stackA = new ArrayDeque<>();
        Deque<ListNode> stackB = new ArrayDeque<>();
        ListNode curA = headA, curB = headB;
        while(curA != null){
            stackA.addLast(curA);
            curA = curA.next;
        }
        while(curB != null){
            stackB.addLast(curB);
            curB = curB.next;
        }
        ListNode ans = null;
        while(!stackA.isEmpty() && !stackB.isEmpty()){
            if(stackA.getLast() == stackB.getLast()){
                ans = stackA.getLast();
                stackA.removeLast();
                stackB.removeLast();
            }else
                break;
        }
        return ans;
    }
}


//two pointers
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null)  return null;
        ListNode curA = headA, curB = headB;
        while(curA != curB){
            curA = (curA != null)? curA.next: headB;
            curB = (curB != null)? curB.next: headA;
        }
        return curA;
    }
}
