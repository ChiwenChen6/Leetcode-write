# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def get_result(self,root,maxi):
        if root==None:
            return
        if root.val>=maxi:
            self.result+=1
            maxi = root.val
        self.get_result(root.left,maxi)
        self.get_result(root.right,maxi)
            
    
    def goodNodes(self, root: TreeNode) -> int:
        self.result = 0
        self.get_result(root,root.val)
        return self.result
