#include <vector>
#include <stack>

class Solution {
public:
    //iterative traversal
    vector<int> inorderTraversal(TreeNode* root) {    
        std::vector<int> res;
        std::stack<TreeNode*> stk;
        while(root || !stk.empty()){
            //push all left node into stack and move the left-most.
            while(root){
                stk.push(root);
                root = root->left;
            }
            //record the first node in stack to result.
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            //right subtree traversal.
            root = root->right;
        }
        return res;
    }
};
