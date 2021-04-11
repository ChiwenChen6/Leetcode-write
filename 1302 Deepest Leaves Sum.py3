# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        """
        :type root: TreeNode
        :rtype: int
        """
        d = {}
        self.foo(root, 0,d)
        return d[max(d.keys())]
        
    def foo(self, root, level = 0, d = {}):
        
        if root != None:
            if level in d.keys():
                d[level] += root.val
            else:
                d[level] = root.val
        
            self.foo(root.right, level + 1, d)   
            self.foo(root.left, level + 1, d)
            
# Runtime: 100 ms, faster than 39.61% of Python3 online submissions for Deepest Leaves Sum.
# Memory Usage: 17.8 MB, less than 40.88% of Python3 online submissions for Deepest Leaves Sum.


class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        q, ans, qlen, curr = [root], 0, 0, 0
        while len(q):
            qlen, ans = len(q), 0
            for _ in range(qlen):
                curr = q.pop(0)
                ans += curr.val
                if curr.left: q.append(curr.left)
                if curr.right: q.append(curr.right)
        return ans
