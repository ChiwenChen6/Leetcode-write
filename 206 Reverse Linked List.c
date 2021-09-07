/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *current = head; 
    struct ListNode *prev = NULL;  
    struct ListNode *next = NULL;  

    while(current!=NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}


Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Linked List.
Memory Usage: 6.4 MB, less than 68.89% of C online submissions for Reverse Linked List.
