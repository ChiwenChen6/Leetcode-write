# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        if root is None:
            return False
        
        def inOrderT(root): #Inorder Traversal 
            if root:
                
                inOrderT(root.left)
                inorder.append(root.val)
                inOrderT(root.right)
        inorder = []
        inOrderT(root)
        
        start, end = 0, len(inorder)-1
        
        while start < end:   # Two pointer method
            if inorder[start] + inorder[end] == k:
                return True
            elif inorder[start] + inorder[end] > k:
                end -= 1
            else:
                start += 1
