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
    List<List<Integer>> ret = new ArrayList<>();
    List<Integer> path = new ArrayList<Integer>();

    public List<List<Integer>> pathSum(TreeNode root, int target) {
        dfs(root, target, 0);
        return ret;
    }

    public void dfs(TreeNode node, int target, int sum){
        if(node == null){
            return;
        }
        sum += node.val;
        path.add(node.val);

        if(sum == target && node.left == null && node.right == null){
            ret.add(new ArrayList<Integer>(path));
        }else{
            dfs(node.left, target, sum);
            dfs(node.right, target, sum);
        } 
        path.remove(path.size() - 1);
    }
}