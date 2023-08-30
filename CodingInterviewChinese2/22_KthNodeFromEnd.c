/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if(head == NULL){
        return NULL;
    }
    if(k == 0){
        return NULL;
    }
    struct ListNode* p1 = head, * p2 = head;
    int counter = 0;
    while(p1->next != NULL){
        counter++;
        p1 = p1->next;
        if(counter < k){
            continue;
        }else{
            p2 = p2->next;
        }
    }
    return p2;
}