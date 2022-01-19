# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        l = []
        if not head:
            return None
        node = head
        while node.next:
            if id(node) in l:
                return node
            else:
                l += [id(node)]
                node = node.next
        return None
