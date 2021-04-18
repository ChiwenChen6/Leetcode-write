# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        len_ = 0
        temp = head
        while temp:
            len_ += 1
            if temp.next is None:
                break
            temp = temp.next
        print(len_)
        if len_ == 1:
            head = None
            return head
        elif (len_ - n)== 0:
            head = head.next
            return head
        else:
            len_ -= n
            c = 0
            temp = head
            while temp:
                c+=1
                if c == len_:
                    break
                temp = temp.next
            temp.next = temp.next.next
            return head
        
