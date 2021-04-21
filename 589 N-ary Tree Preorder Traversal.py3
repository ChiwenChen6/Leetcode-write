"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node', ans: list = None) -> List[int]:
        if not root: return ans
        if ans == None: ans = []
        ans.append(root.val)
        for child in root.children:
            self.preorder(child, ans)
        return ans
      
#       Runtime: 48 ms, faster than 81.20% of Python3 online submissions for N-ary Tree Preorder Traversal.
# Memory Usage: 15.9 MB, less than 98.41% of Python3 online submissions for N-ary Tree Preorder Traversal.
