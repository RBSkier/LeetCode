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
    private Map<Integer, Integer> inorderIndex;

    private TreeNode buildTreeCore(int[] preorder, int[] inorder, int preLeft, int preRight, int inLeft, int inRight){
        if(preLeft > preRight) 
            return null;
        // get the index of root in inorder array.
        int inRoot = inorderIndex.getOrDefault(preorder[preLeft], -1);
        // create root node.
        var root = new TreeNode(preorder[preLeft]);
        // get the length of left subtree.
        int len = inRoot - inLeft;
        // build left and right subtree.
        root.left = buildTreeCore(preorder, inorder, 
            preLeft + 1, preLeft + len, 
            inLeft, inRoot - 1);
        root.right = buildTreeCore(preorder, inorder, 
            preLeft + len + 1, preRight, 
            inRoot + 1, inRight);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        inorderIndex = new HashMap<Integer, Integer>();
        for(int i = 0; i < inorder.length; i++){
            inorderIndex.put(inorder[i], i);
        }
        return buildTreeCore(preorder, inorder, 0, n - 1, 0, n -1);
    }

}







