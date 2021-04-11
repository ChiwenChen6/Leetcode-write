/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    private int maxLevel;
    private int sum;
    public int DeepestLeavesSum(TreeNode root) {
        Traverse(root, 0);
        return sum;
    }
    
    private void Traverse(TreeNode node, int level)
    {
        if(node == null) return;
        Traverse(node.left, level+1);
        if(level > maxLevel)
        {
            maxLevel = level;
            sum = node.val;
        }
        else if(level == maxLevel)
            sum += node.val;
        Traverse(node.right, level+1);
    }
}


Runtime: 120 ms, faster than 54.97% of C# online submissions for Deepest Leaves Sum.
Memory Usage: 34.9 MB, less than 9.94% of C# online submissions for Deepest Leaves Sum.
