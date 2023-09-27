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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode * curr1 = head, * curr2 = head -> next;
        while(curr1 != nullptr && curr2 != nullptr && curr2 -> next != nullptr) {
            curr1 = curr1 -> next;
            curr2 = curr2 -> next -> next;
            if(curr2 == curr1)  return true;
        }
        return false;
    }
};