/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root){
        if(!root){
            return "";
        }
        string ret;
        queue<TreeNode*> levelOrder;

        levelOrder.push(root);
        while(!levelOrder.empty()){
            TreeNode* node = levelOrder.front();
            levelOrder.pop();
            if (node == nullptr) {
                ret += "null,";
            }else{
                ret += to_string(node->val) + ",";
                levelOrder.push(node->left);
                levelOrder.push(node->right);
            }
        }
        
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        if(data == ""){
            return nullptr;
        }
        queue<TreeNode**> levelQueue;  //层序待填队列
        stringstream ss(data);

        TreeNode* pRoot;
        levelQueue.push(&pRoot);    //初始化待填队列
        while(!levelQueue.empty()){
            string token;
            getline(ss, token, ',');
            if(token == "null" || token == ""){
                levelQueue.pop();
                continue;
            }
            int value = stoi(token);
            TreeNode** ppNode = levelQueue.front();
            levelQueue.pop();
            *ppNode = new TreeNode(value);  //*ppNode = pNode, 当还有值的时候才为待创建的节点申请空间并初始化值
            //将该节点的左右节点放入待创建队列
            levelQueue.push(&(*ppNode)->left);
            levelQueue.push(&(*ppNode)->right);
        }
        // deserializeCore(&levelQueue, &ss);

        return pRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codcodecec.serialize(root));