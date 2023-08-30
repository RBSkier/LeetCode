/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }

    struct ListNode* mergeList = NULL, * cur = NULL;
    if(l1->val <= l2->val){
        mergeList = l1;
        l1 = l1->next;
    }else{
        mergeList = l2;
        l2 = l2->next;
    }
    cur = mergeList;

    while(true){
        //如果其中一个链表遍历完了，则直接将另一个列表全部append到mergeList就结束了
        if(l1 == NULL){
            cur->next = l2;
            break;
        }
        if(l2 == NULL){
            cur->next = l1;
            break;
        }
        //否则判断大小并摘除最小结点放入mergeList
        if(l1->val <= l2->val){
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }else{
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }

    return mergeList;
}
