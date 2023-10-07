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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();
        if(N == 0) return nullptr;

        for(int sz = 1; sz < N; sz = sz+sz) //sz: subarray size.
            for(int lo = 0; lo+sz < N; lo += sz+sz)
                lists[lo] = merge(lists[lo], lists[lo+sz]); //reuse the lists to store merge result.
        return lists[0];
    }
private:
    ListNode* merge(ListNode* l, ListNode* r){
        ListNode* dummy = new ListNode(-1), * curr;
        for(curr = dummy; l && r; curr = curr->next){
            if(l->val <= r->val){
                curr->next = l;
                l = l->next;
            }else{
                curr->next = r;
                r = r->next;
            }
        }
        curr->next = l ? l : r;
        return dummy->next;
    }
};

//该题可以套用算法4书籍中自底向上的归并模版，而merge()方法则复用 [21. 合并两个有序链表](/problems/merge-two-sorted-lists/)。如果按所有链表节点总数为n，则时间复杂度是O(Nlogk)，因为是自底向上的方法，可以复用lists的空间，所以空间复杂度只需要O(1)。