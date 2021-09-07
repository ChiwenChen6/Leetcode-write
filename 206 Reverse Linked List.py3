# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        while head:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        return prev
      
      
#       Runtime: 32 ms, faster than 88.76% of Python3 online submissions for Reverse Linked List.
# Memory Usage: 15.7 MB, less than 46.12% of Python3 online submissions for Reverse Linked List.
