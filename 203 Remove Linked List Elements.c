/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL)
        return NULL;
    if(head->val == val) {
        return removeElements(head->next, val);
    } else {
        head -> next = removeElements(head->next, val);
    }
    return head;

}


// Runtime: 12 ms, faster than 78.81% of C online submissions for Remove Linked List Elements.
// Memory Usage: 8.6 MB, less than 6.52% of C online submissions for Remove Linked List Elements.
