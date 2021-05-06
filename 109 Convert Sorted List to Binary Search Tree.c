/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortedArrayToBST(int* array,int size){
    if (size==0) {
        return NULL;
    }
    
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (size==1) {
        root -> val=array[0];
        root -> left=NULL;
        root -> right=NULL;
        return root;
    }
    root->val = array[size/2];
    root->left = sortedArrayToBST(array, size/2);
    root->right = sortedArrayToBST(&array[size/2+1], size-size/2-1);
    return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int* array = (int*)calloc(17000,sizeof(int));
    int count = 0;
    while(head != NULL) {
        array[count++] = head->val;
        head = head->next;
    }
    if(count == 0) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = array[count/2];
    root->left = sortedArrayToBST(array, count/2);
    root->right = sortedArrayToBST(&array[count/2+1], count-count/2-1);
    return root;
}
