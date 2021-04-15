/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *partition(struct ListNode *head, int x) {
    if (head == NULL)
        return NULL;

    struct ListNode greaterList = {.val = 0, .next = NULL};
    struct ListNode lessList = {.val = 0, .next = NULL};
    struct ListNode *greater = &greaterList;
    struct ListNode *less = &lessList;

    while (head != NULL) {
        if (head->val < x) {
            less->next = head;
            head = head->next;
            less = less->next;
            less->next = NULL;
        } else {
            greater->next = head;
            head = head->next;
            greater = greater->next;
            greater->next = NULL;
        }
    }

    less->next = greaterList.next;

    return lessList.next;
}
