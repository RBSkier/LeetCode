/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        for(Node* curr = head; curr; curr = curr->next->next){
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
        }

        for(Node* curr = head; curr; curr = curr->next->next){
            Node* clone = curr->next;
            clone->random = (curr->random != nullptr) ? curr->random->next : nullptr;
        }

        Node* result = head->next;
        for(Node* curr = head; curr; curr = curr->next){
            Node* clone = curr->next;
            curr->next = curr->next->next;
            clone->next = (clone->next != nullptr) ? clone->next->next : nullptr; //separate clone linklist 
        }
        return result;
    }
};