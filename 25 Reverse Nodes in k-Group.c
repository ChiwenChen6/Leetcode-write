/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* RevertList(struct ListNode* head, struct ListNode* tail, struct ListNode* preHead)
{
    struct ListNode* p1 = head;
    struct ListNode* p2 = head->next;
    while (p2 != NULL && p2 != tail){
        struct ListNode* n = p2->next;
        p2->next = head;
        p1->next = n;
        head = p2;
        p2 = n;
    }
    
    preHead->next = head;
    return p1;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* tail = head;
    struct ListNode hNode = {0,head};
    struct ListNode* preHead = &hNode;
    while (tail != NULL) {
        for (int i = 0;i < k; i++){
            if (tail == NULL) {
                return hNode.next;
            }
            tail = tail->next;

        }
        preHead = RevertList(head, tail, preHead);
        head = tail;
        
    }
    return hNode.next;
}



// 62 / 62 test cases passed.
// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 7.2 MB
// Submitted: 2 minutes ago


