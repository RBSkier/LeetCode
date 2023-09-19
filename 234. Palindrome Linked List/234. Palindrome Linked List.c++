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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)   return true;
        ListNode* firstHalfEnd = getMiddleNode(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        //if exist a node value doesn't match, set flag as false.
        bool flag = true;
        ListNode* cur1 = head, * cur2 = secondHalfStart;
        while(cur2 != nullptr){
            if(cur1->val != cur2->val) flag = false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        reverseList(secondHalfStart);
        return flag;
    }
private:
    ListNode* getMiddleNode(ListNode* head){
        ListNode* fast = head, * slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* halfHead){
        ListNode* pre = nullptr, * cur = halfHead;
        while(cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

/*
pre <- cur cur.next
       pre cur
*/
