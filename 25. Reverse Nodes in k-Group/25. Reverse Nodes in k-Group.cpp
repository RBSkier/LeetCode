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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int n = 0;
        for (ListNode *cur = head; cur; cur = cur->next)
            ++n; // count the length of list.

        ListNode *dummy = new ListNode(0, head), *p0 = dummy;
        ListNode *pre = nullptr, *cur = head;
        for (; n >= k; n -= k) {
            for (int i = 0; i < k; ++i) { //the same as question 206.
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }

            ListNode *temp = p0->next; //record the new segment tail.
            p0->next = pre; //p0 change to link the new segment head.
            p0 = temp; //update p0 from old segment tail to new segment tail.
            
            p0->next = cur; //link the new segment tail to the rest list.
        }
        return dummy->next;
    }
};
