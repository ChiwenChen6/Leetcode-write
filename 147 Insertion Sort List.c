/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
   if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode **p, *node, *next;
    
    node = head->next;
    head->next = NULL;
    while (node) {
        p = &head;
        next = node->next;
        while (*p && (*p)->val <= node->val) {
            p = &(*p)->next;
        }
        if (*p) {
            node->next = *p;
            *p = node;
        } else {
            node->next = NULL;
            *p = node;
        }
        node = next;
    }
    return head;
}
