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
    
    LinkedList<Integer> flippedNodesVal;
    int index;
    int[] voyage;
    
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        // main
        flippedNodesVal = new LinkedList();
        index = 0;
        this.voyage = voyage;
        dfs(root);
        return new ArrayList<Integer>(flippedNodesVal);
    }
    
    private boolean dfs(TreeNode node){
        if(node == null) {
            return true;
        }
        if(node.val != voyage[index]){
            flippedNodesVal.clear();
            flippedNodesVal.add(-1);
            return false;
        }
        index++;
        if(index < voyage.length && node.left != null && node.left.val != voyage[index]){
            flippedNodesVal.add(node.val);
            if(!dfs(node.right)) {
                return false;
            }
            return dfs(node.left);
        }else{
            if(!dfs(node.left)) {
                return false;
            }
            return dfs(node.right);
        }
    }
}



// 2nd solution
class Solution {
    int vix = 0;
    List<Integer> ans = new ArrayList<>();
    private void dfs(TreeNode node, int[] V) {
        if (node == null || (ans.size() != 0 && ans.get(0) == -1)) return;
        if (node.val != V[vix++])
            ans = new ArrayList<Integer>(Arrays.asList(-1));
        else if (node.left != null && node.left.val != V[vix]) {
            ans.add(node.val);
            dfs(node.right, V);
            dfs(node.left, V);
        } else {
            dfs(node.left, V);
            dfs(node.right, V);
        }
    }
    public List<Integer> flipMatchVoyage(TreeNode root, int[] V) {
        dfs(root, V);
        return ans;
    }
}
