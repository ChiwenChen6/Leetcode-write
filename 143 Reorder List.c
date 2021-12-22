/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *find_mid(struct ListNode *head) {
   struct ListNode *fast = head;
   struct ListNode *slow = head;
   while (fast && (fast->next)) {
      fast = fast->next->next;
      slow = slow->next;
   }
   return slow;
}

struct ListNode *reverse_list(struct ListNode *head) {
   struct ListNode *cur = head;
   struct ListNode *pre = NULL;
   while (cur) {
      struct ListNode *next_node = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next_node;
   }
   return pre;
}

void reorderList(struct ListNode *head) {
   if (NULL == head) {
      return;
   }
   // 1: Find middle point
   struct ListNode *mid = find_mid(head);
   // 2: divide list
   struct ListNode *sec = mid->next;
   mid->next = NULL;
   // 3: reverse second list
   sec = reverse_list(sec);
   // 4: merge lists
   struct ListNode *fst_node = head;
   struct ListNode *sec_node = sec;
   while (sec_node) {
      struct ListNode *fst_next = fst_node->next;
      struct ListNode *sec_next = sec_node->next;
      fst_node->next = sec_node;
      sec_node->next = fst_next;
      fst_node = fst_next;
      sec_node = sec_next;
   }
}
