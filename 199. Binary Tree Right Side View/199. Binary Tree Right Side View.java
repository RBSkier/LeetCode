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
    private List<Integer> ret = new ArrayList<>();

    public List<Integer> rightSideView(TreeNode root) {
        dfs(root, 0);
        return ret;
    }

    private void dfs(TreeNode root, int depth){
        if(root == null) return;
        if(++depth > ret.size())
            ret.add(root.val);   //if the node is the iterated node of new level.
        dfs(root.right, depth);
        dfs(root.left, depth);
    }
}
