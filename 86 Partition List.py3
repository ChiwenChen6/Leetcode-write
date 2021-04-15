# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if not head:
            return None
        if not head.next:
            return head

        # >= x
        prev = None
        cur = head
        while cur and cur.val < x:
            prev = cur
            cur = cur.next
        new_head = head

        #  < x
        slow = prev
        fast = cur
        while fast:
            if fast.val < x:
                slow.next = fast.next
                fast.next = None
                if not prev:
                    prev = fast

                    new_head = prev
                    prev.next = head
                else:
                    prev.next = fast
                    fast.next = cur
                    prev = prev.next

                fast = slow.next
            else:
                slow = fast
                fast = fast.next

        return new_head
# Status: Accepted
# Runtime: 36 ms
# Memory Usage: 14.2 MB
