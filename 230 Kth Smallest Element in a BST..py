
"""
Created on Tues Nov. 10 21:49 2020
Old version and rewrite here
@author: Chiwen Chen
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(self, root, ansval):
    if root.left != None:
        dfs(self, root.left, ansval)
    ansval.append(root.val)
    if root.right != None:
        dfs(self, root.right, ansval)
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        ansval=[]
        dfs(self, root, ansval)
        return ansval[k-1]
    
"""Runtime: 8 ms, faster than 96.69% of C online submissions for Kth Smallest Element in a BST.
Memory Usage: 10.2 MB, less than 16.02% of C online submissions for Kth Smallest Element in a BST."""