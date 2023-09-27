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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, * slow = head;
        while(true){
            if(fast == nullptr || fast->next == nullptr)    return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)    break;
        }
        //from the meetion of fast and slow to the meetion of slow and ptr3.
        ListNode* ptr3 = head;
        while(ptr3 != slow){
            ptr3 = ptr3->next;
            slow = slow->next;
        }
        return slow;
    }
};