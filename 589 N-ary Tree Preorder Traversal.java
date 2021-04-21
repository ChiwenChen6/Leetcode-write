class Solution {
    List<Integer> ans = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        if (root == null) 
            return ans;
        ans.add(root.val);
        for (Node child : root.children)
            preorder(child);
        return ans;
    }
}
