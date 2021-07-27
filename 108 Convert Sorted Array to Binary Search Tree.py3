# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        
        midelement = (len(nums))//2
        root = TreeNode(nums[midelement])
        root.left = self.sortedArrayToBST( nums[:midelement])
        root.right = self.sortedArrayToBST( nums[midelement + 1:])

        return root
      
      
# Runtime: 56 ms, faster than 88.64% of Python3 online submissions for Convert Sorted Array to Binary Search Tree.
# Memory Usage: 15.7 MB, less than 59.74% of Python3 online submissions for Convert Sorted Array to Binary Search Tree.
