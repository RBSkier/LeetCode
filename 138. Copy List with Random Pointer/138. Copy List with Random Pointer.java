/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;

        for(Node curr = head; curr != null; curr = curr.next.next){
            Node clone = new Node(curr.val);
            clone.next = curr.next;
            curr.next = clone;
        }

        for(Node curr = head; curr != null; curr = curr.next.next){
            Node clone = curr.next;
            clone.random = (curr.random != null) ? curr.random.next : null;
        }

        Node result = head.next;
        for(Node curr = head; curr != null; curr = curr.next){
            Node clone = curr.next;
            curr.next = curr.next.next;
            clone.next = (clone.next != null) ? clone.next.next : null; //separate clone linklist 
        }
        return result;
    }
}