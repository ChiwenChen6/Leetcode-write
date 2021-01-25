# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return  None
        while len(lists) > 1:
            newlists = []
            i = 0
            while len(lists) > (i + 1):
                l1 = lists[i]
                l2 = lists[i+1]
                newlists.append(merge(l1, l2))
                i += 2
            if i == len(lists) - 1:
                newlists.append(lists[-1])
            lists = newlists
        return lists[0]    
    
def merge(l1, l2):
    now =  ListNode(0)
    tmp = now #remenber ListNode point will change. save list first 
    while l1 or l2:
        if l1 and l2:
            if l1.val > l2.val:
                now.next = l2
                l2 = l2.next
            else:
                now.next = l1
                l1 = l1.next
        elif l1:
            now.next = l1 
            l1 = None
        else:
            now.next = l2
            l2 = None
        now = now.next
    return tmp.next

    
