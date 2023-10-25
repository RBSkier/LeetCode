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


//方法一：寻找前驱节点，时间复杂度O(n)，空间复杂度O(n)。
class Solution {
    public void flatten(TreeNode root) {
        for(var cur = root; cur != null; cur = cur.right){
            if(cur.left == null) continue;
            TreeNode pre = cur.left;
            while(pre.right != null)
                pre = pre.right;
            pre.right = cur.right;
            cur.right = cur.left;
            cur.left = null;
        }
    }
}

//方法二：变体后序遍历，递归
class Solution {
    private TreeNode pre = null; //record the ordered linked list.

    public void flatten(TreeNode root) {
        if(root == null) return;
        //postorder traversal variant.
        flatten(root.right);
        flatten(root.left);
        root.right = pre;
        root.left = null;
        pre = root;
    }
}