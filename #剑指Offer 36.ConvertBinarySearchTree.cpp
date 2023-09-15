/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* fakeHead = new Node(), *tail = fakeHead;

    void midOrder(Node* node){
        if(!node){
            return;
        }
        midOrder(node->left);
        tail->right = node;
        node->left = tail;
        tail = tail->right;
        midOrder(node->right);
    }

    Node* treeToDoublyList(Node* root) {
        if(!root){
            return nullptr;
        }
        midOrder(root);
        Node* head = fakeHead->right;
        tail->right = head;
        head->left = tail;

        return head;
    }
};