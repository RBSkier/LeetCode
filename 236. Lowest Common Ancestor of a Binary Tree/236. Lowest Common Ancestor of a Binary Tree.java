/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// 核心思想，一个点是最近公共节点 1.自己是其中一个节点，另一个节点在左右子树。 2.左右子树各含一个节点

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;

        var ret1 = lowestCommonAncestor(root.left, p, q);
        var ret2 = lowestCommonAncestor(root.right, p, q);
		// 如果当前节点命中，返回当前节点
        if(root == p || root == q) return root;
		// 如果左右都命中，则当前节点是最近公共节点
        else if(ret1 != null && ret2 != null) return root;
		// 否则如果是左有值，继续传递左值
        else if(ret1 != null && ret2 == null) return ret1;
		// 否则如果是右有值，继续传递右值
        else if(ret2 != null && ret1 == null) return ret2;
		// 剩余情况返回null即可
        else return null;
    }
}