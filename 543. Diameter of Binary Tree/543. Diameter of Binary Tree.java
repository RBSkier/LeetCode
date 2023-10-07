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
    private int res = -1;
    private int dfs(TreeNode root){
        if(root == null) return 0; // if null, end traversal.
        int L = dfs(root.left);
        int R = dfs(root.right);
        res = Math.max(L + R, res); // maintain the max path while traversal.
        return Math.max(L, R) + 1; // return the depth of this tree.
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        dfs(root);
        return res;
    }
}