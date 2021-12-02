# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        temp2 = head
        c = 1
        while temp2.next:
            temp2 = temp2.next
            c += 1
        i = 0
        previous = head
        temp1 = head
        while i < c:
            if i % 2 != 0:
                temp2.next = ListNode(temp1.val)
                temp2 = temp2.next
                previous.next = previous.next.next
                previous = previous.next
            temp1 = temp1.next
            i += 1
        return head
      
#       Runtime: 48 ms, faster than 40.20% of Python3 online submissions for Odd Even Linked List.
# Memory Usage: 16.4 MB, less than 56.86% of Python3 online submissions for Odd Even Linked List.
