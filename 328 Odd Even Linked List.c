/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (!head || !head->next)
        return head;
    
    struct ListNode *odd, *even, *help;
    odd = head;
    even = head->next;
    help = head->next;
    
    while (odd->next != NULL && odd->next->next != NULL) { 
        odd->next = odd->next->next;
        odd = odd->next;
        
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = help;
    
    return head;
}


Runtime: 4 ms, faster than 91.43% of C online submissions for Odd Even Linked List.
Memory Usage: 7.1 MB, less than 35.00% of C online submissions for Odd Even Linked List.
