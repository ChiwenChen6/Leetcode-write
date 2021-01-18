    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dum = ListNode(None)
        prev = dum
        
        while l1 and l2:
            if l1.val <= l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            prev = prev.next
        
        if l1 == None:
            prev.next = l2
        elif l2 == None:
            prev.next = l1
        
        return dum.next
