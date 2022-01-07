/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct {
        struct ListNode* head    
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    srand(time(NULL));
    Solution* sul = malloc(sizeof(Solution));
    sul->head=head;
    return sul;
}

int solutionGetRandom(Solution* obj) {
    
    int count = 0;
    struct ListNode* temp;
    struct ListNode* head;
    temp = obj->head;
    head = temp;
    int i;
    while(head!=NULL) {
        head=head->next;
        count++;
    }

    int  r= random()%count; 
    head = temp;
    for(i=0;i<r;i++) {
        head = head->next;
    }
    return head->val;
}

void solutionFree(Solution* obj) {
    free(obj);
}


/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/



