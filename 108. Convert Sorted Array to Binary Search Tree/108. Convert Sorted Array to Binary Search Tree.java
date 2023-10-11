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
    
    private TreeNode core(int l, int r, int[] nums){
        if(l > r) return null;
        int mid = (l + r) / 2;
        TreeNode root = new TreeNode(nums[mid]); //use the middle num as the root value.
        root.left = core(l, mid-1, nums); // create left subtree and append the root node.
        root.right = core(mid+1, r, nums); // create right subtree and append the root node.
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return core(0, nums.length-1, nums);
    }
}
