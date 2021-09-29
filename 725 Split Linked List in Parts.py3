# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def length(self, head):
        length = 0
        while head != None:
            length += 1
            head = head.next
        return length
    
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        res = [None] * k
        if not root or k <= 0:
            return res
        length = self.length(root)
        parlen = length // k
        remain = length % k
        """
        for the first remain part len = parlen + 1
        """
        res = [None] * k
        prev, head = None, root
        for i in range(k):
            res[i] = head
            for j in range(parlen + (1 if i <= (remain - 1) else 0)):
                prev = head
                head = head.next
            if prev != None:
                prev.next = None
        return res
