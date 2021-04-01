/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* NextNode = NULL;

    while(curr){
        NextNode = curr -> next;
        curr-> next = prev;
        prev = curr;
        curr = NextNode;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {

    if(head == NULL)
        return true;
    struct ListNode* fast = head;
    struct ListNode* slow = head; 

    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next ->next;
    }
    slow -> next = reverse(slow -> next);
    slow = slow -> next;

    while(slow != NULL){
        if(head -> val != slow -> val)
            return false;
        slow = slow -> next;
        head = head -> next;
    }
    return true;
}
// Runtime: 128 ms, faster than 26.09% of C online submissions for Palindrome Linked List.
// Memory Usage: 41.1 MB, less than 53.23% of C online submissions for Palindrome Linked List.
