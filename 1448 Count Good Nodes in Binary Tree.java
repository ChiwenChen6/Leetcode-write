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
    
    private int count;
    
    public int goodNodes(TreeNode root) {
        dfs(root, root.val);
        return count;
    }
    
    private void dfs(TreeNode node, int maxSoFar) {
        if (node == null) {
            return;
        }
        if (node.val >= maxSoFar) {
            count++;
        }
        dfs(node.left, Integer.max(maxSoFar, node.val));
        dfs(node.right, Integer.max(maxSoFar, node.val));
    }
}
