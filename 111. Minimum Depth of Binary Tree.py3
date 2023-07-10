# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root: 
            return 0

    
        level = 0
        stack = deque([root]) 

        while stack:
            level+= 1
            for x in range(len(stack)):

                n = stack.popleft()
                
                if not n.left and not n.right: 
                    return level

                if n.left : 
                    stack.append(n. left)
                if n.right: 
                    stack.append(n.right)
