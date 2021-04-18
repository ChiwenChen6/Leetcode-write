/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* temp=head;
    struct ListNode* del;
    int count=0, pos;
    
    while(temp!=NULL)
    {
        ++count;
        temp=temp->next;
    }
    pos = count-n;
    if (pos == 0) {
        head = head->next;
        return head;
    }
    
    if (pos == 0) {
        head = head->next;
        return head;
    }
    
    temp = head;
    if (pos < 0)
    {
        return head;
    }
    for(count=0;count<pos-1;count++)
    {
        temp = temp->next;        
    }    
    if (temp->next != NULL) { 
        del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }
    return head;
}



// Status: Accepted
// Runtime: 24 ms
// Memory Usage: 14.4 MB
