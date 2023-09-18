/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)  return nullptr;
        ListNode * curA = headA, * curB = headB;
        while(curA != curB){
            curA = (curA != nullptr)? curA->next: headB;
            curB = (curB != nullptr)? curB->next: headA;
        }
        return curA;
    }
};
