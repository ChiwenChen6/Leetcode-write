# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = result_list = ListNode()
        carry = 0
        
        while l1 or l2 or carry:
            tmp_val1 = l1.val if l1 else 0
            tmp_val2 = l2.val if l2 else 0
            
            summ = tmp_val1 + tmp_val2 + carry
            
            if summ > 9:
                carry = 1
                summ -= 10
            else:
                carry = 0
            
            dummy_head.val = summ
            
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            if l1 or l2 or carry:
                dummy_head.next = ListNode()
                dummy_head = dummy_head.next
        # end of while.
        return result_list
