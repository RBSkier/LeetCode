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
    private boolean core(TreeNode left, TreeNode right) {
        if(left == null && right == null) return true;
        else if(left == null || right == null) return false;

        return left.val == right.val  //two nodes' values are the same.
            && core(left.left, right.right) //if left node's left subtree is symmetric to right node's right subtree.
            && core(left.right, right.left); //if left node's right subtree is symmetric to right node's left subtree.
    }
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        //recursive DFS.
        return core(root.left, root.right);
    }
}
