# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
	def isPalindrome(self, head: ListNode) -> bool:
        
		full_number = []
        
		while head != None:
			full_number.append(head.val)
			head = head.next
            
		if full_number == full_number[::-1]:
			return True
		return False
  
#   Runtime: 848 ms, faster than 15.83% of Python3 online submissions for Palindrome Linked List.
# Memory Usage: 47.3 MB, less than 18.52% of Python3 online submissions for Palindrome Linked List.
