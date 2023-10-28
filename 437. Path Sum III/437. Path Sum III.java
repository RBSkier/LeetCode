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
    public int pathSum(TreeNode root, int targetSum) {
        preSumMap = new HashMap<Long, Integer>();
        preSumMap.put(0L, 1);
        DFS(root, 0, targetSum);
        return res;
    }
    
    private void DFS(TreeNode root, long preSum, int targetSum) {
        if(root == null) return;
        
        // check for new solutions.
        long curr = preSum + root.val;
        res += preSumMap.getOrDefault(curr - targetSum, 0);
        // update the preSumMap after.
        preSumMap.put(curr, preSumMap.getOrDefault(curr, 0) + 1); 
        // recursive call DFS.
        DFS(root.left, curr, targetSum);
        DFS(root.right, curr, targetSum);
        preSumMap.put(curr, preSumMap.getOrDefault(curr, 0) - 1);
    }

    private Map<Long, Integer> preSumMap;
    private int res = 0;
}