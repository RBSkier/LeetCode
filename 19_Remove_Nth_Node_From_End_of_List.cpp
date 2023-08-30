/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy= new ListNode(-1);
        ListNode* p1 = dummy;
        ListNode* p2 = dummy;
        dummy->next = head;
        for (int i=0;i<n;i++){
            p1=p1->next;
        }
        // if (p1==nullptr){
        //     return head;
        // }
        while(p1->next!=nullptr){
            p1=p1->next;
            p2=p2->next;
        }
        // p2->next is last n th node
        p2->next = p2->next->next;
        return dummy->next;
    }
};