# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.ans = 0
        def getSum(node):
            if not node:
                return 

            if low <= node.val <= high:
                self.ans += node.val
                getSum(node.left)
                getSum(node.right)
                
            elif node.val < low:
                getSum(node.right)
            else:
                getSum(node.left)
            
        getSum(root)
        
        return self.ans
