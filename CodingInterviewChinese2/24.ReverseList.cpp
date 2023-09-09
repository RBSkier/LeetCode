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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* new_head = NULL, * temp = NULL;
        while(head != NULL){
            temp = head->next;
            head->next = new_head;
            new_head = head;
            head = temp;
        }

        return new_head;
    }
};
