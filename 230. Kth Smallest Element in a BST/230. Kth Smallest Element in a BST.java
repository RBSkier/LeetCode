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
    private int ret = -1;
    private int accumulation = 0; //记录累计遍历的元素个数
    private void inOrderTraversal(TreeNode root, int k){
        if(root == null) return; //递归结束条件
        inOrderTraversal(root.left, k);
        if(++accumulation == k) ret = root.val; //判断当前节点是否为第k个便利的节点
        inOrderTraversal(root.right, k); //返回自己为根的树的总节点数
    }
    public int kthSmallest(TreeNode root, int k) {
        inOrderTraversal(root, k);
        return ret;
    }
}
