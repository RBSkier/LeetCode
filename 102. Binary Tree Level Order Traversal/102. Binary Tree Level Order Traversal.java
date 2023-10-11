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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null) return new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        Qeque<TreeNode> q = new LinkedList<>();
        q.addLast(root);
        for(int N = q.size(); N != 0; N = q.size()){
            res.add(new ArrayList<Integer>());   //directly place the val in res can reduce the time of copy vector.
            for(int i = 0; i < N; i++){
                TreeNode node = q.poll();
                if(node.left != null) q.offer(node.left);
                if(node.right != null) q.offer(node.right);
                res.get(res.size()-1).add(node.val);
            }
        }
        return res;
    }
}
