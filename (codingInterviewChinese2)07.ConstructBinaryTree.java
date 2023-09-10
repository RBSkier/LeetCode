/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private Map<Integer, Integer> indexMap;

    public TreeNode myBuildTree(int[] preorder, int[] inorder,int preorder_left,int preorder_right, int inorder_left, int inorder_right){

        if (preorder_left > preorder_right) {
            return null;
        }

        //获取根节点的值，并创建一个根节点
        int preorder_root = preorder_left;
        int rootVal = preorder[preorder_left];
        TreeNode root =new TreeNode(rootVal);
        //查找该根节点在中序数组的下标
        int inorder_root = indexMap.get(preorder[preorder_root]);

        //得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;

        root.left = myBuildTree(preorder, inorder,
                preorder_left + 1,preorder_left + size_left_subtree,
                inorder_left,inorder_root - 1);
        root.right = myBuildTree(preorder,inorder,
                preorder_left + size_left_subtree + 1,preorder_right,
                inorder_root + 1,inorder_right);

        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        indexMap = new HashMap<Integer,Integer>();
        for(int i=0;i<n;i++){
            indexMap.put(inorder[i],i);
        }
        return myBuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
}