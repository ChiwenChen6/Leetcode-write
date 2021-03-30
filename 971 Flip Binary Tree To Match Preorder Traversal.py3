# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        ans = [0]
        def dfs(node, voyage, ans):
            if not node or ans[0] == -1: 
                return
            if node.val != voyage[ans[0]]: 
                ans[0] = -1
            else:
                ans[0] += 1
                if node.left and node.left.val != voyage[ans[0]]:
                    ans.append(node.val)
                    dfs(node.right, voyage, ans)
                    dfs(node.left, voyage, ans)
                else:
                    dfs(node.left, voyage, ans)
                    dfs(node.right, voyage, ans)
        dfs(root, voyage, ans)
        
        return ans[:1] if ans[0] == -1 else ans[1:]
