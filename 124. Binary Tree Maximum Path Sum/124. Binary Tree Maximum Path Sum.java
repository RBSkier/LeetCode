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
    public int maxPathSum(TreeNode root) {
        maxValue = Integer.MIN_VALUE;
        maxPathSumCore(root);
        return maxValue;
    }

    private int maxPathSumCore(TreeNode root) {
        if(root == null) return 0;

        int left = Math.max(0, maxPathSumCore(root.left));
        int right = Math.max(0, maxPathSumCore(root.right));
        int case1 = root.val + left + right;    //路径经过当前节点的左右节点的情况下的最优解。
        maxValue = Math.max(maxValue, case1);
        return root.val + Math.max(left, right); //路径不经过当前节点的左右节点的情况下，将最优解作为子问题的解返回给父节点
    }

    private int maxValue;
}

/*
后序遍历
递归返回经过该节点的最大序列
*/
