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
        if(headA == nullptr || headB == nullptr)
            return nullptr;

        int m = 0, n = 0;
        ListNode * curA = headA, * curB = headB;
        do{
            m++;
            curA = curA -> next;
        }while(curA != nullptr);
        do{
            n++;
            curB = curB -> next;
        }while(curB != nullptr);

        int gap = abs(m - n);
        //第二轮快慢指针遍历
        curA = headA, curB = headB;
        if(m > n)
            for(int i = 1; i <= gap; i++){
                curA = curA -> next;
            }
        else if(m < n)
            for(int i = 1; i <= gap; i++){
                curB = curB -> next;
            }
        while(curA != nullptr){
            if(curA == curB)    //如果相同结点
                return curA;
            curA = curA -> next;
            curB = curB -> next;
        }

        return nullptr;
    }
};
