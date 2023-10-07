/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        //iterative traversal   
        List<Integer> res = new ArrayList<>();
        Deque<TreeNode> stk = new LinkedList<>();
        while(root != null || !stk.isEmpty()){
            //push all left node into stack and move the left-most.
            while(root != null){
                stk.push(root);
                root = root.left;
            }
            //record the first node in stack to result.
            root = stk.pop();
            res.add(root.val);
            //right subtree traversal.
            root = root.right;
        }
        return res;
    }
}
