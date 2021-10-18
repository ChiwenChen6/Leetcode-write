# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        array = [(root, None)]
        while array:
            foundx = foundy = None
            new = []
            for node, parent in array:
                if node.val == x: foundx = parent
                if node.val == y: foundy = parent
                if node.left: new.append((node.left, node))
                if node.right: new.append((node.right, node))
            array = new
            if foundx and foundy and foundy != foundx:
                return True
        return False
      
      
# Runtime: 55 ms, faster than 13.46% of Python3 online submissions for Cousins in Binary Tree.
# Memory Usage: 14.4 MB, less than 9.47% of Python3 online submissions for Cousins in Binary Tree.
