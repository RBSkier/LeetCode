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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;

        int digit1, digit2, sum;
        int carry = 0;
        struct ListNode* head = nullptr;
        struct ListNode* tail = nullptr;

        while(l1 != nullptr || l2 != nullptr){
            digit1 = l1 ? l1 -> val: 0;
            digit2 = l2 ? l2 -> val: 0;
            sum = digit1 + digit2 + carry;

            if(!head)
                head = tail = new struct ListNode(sum % 10);  //插入结点
            else{
                tail -> next =  new struct ListNode(sum % 10);  //插入结点
                tail = tail -> next;
            }

            carry = sum / 10;
            if(l1)  l1 = l1 -> next;
            if(l2)  l2 = l2 -> next;
        }

        if(carry != 0)
            tail -> next =  new struct ListNode(carry);

        return head;
    }
};

