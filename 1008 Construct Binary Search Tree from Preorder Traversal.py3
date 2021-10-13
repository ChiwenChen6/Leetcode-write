# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return []
        
        def construct(nums, s, e):
            if s == e:
                return None
            node = TreeNode(nums[s])
            end = e
            for i in range(s+1, e):
                if nums[s] < nums[i]:
                    end = i
                    break
            node.left = construct(nums, s+1, end)
            node.right = construct(nums, end, e)
            return node
    
        root = construct(preorder, 0, len(preorder))
        return root
