/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int * node;
    int length;
    int pos;
} BSTIterator;

void inorder(struct TreeNode * root, int * out, int * idx)
{
    if(root == NULL) {
        return;
    }
    inorder(root->left, out, idx);
    out[(*idx)++] = root->val;
    inorder(root->right, out, idx);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator * result = (BSTIterator *)malloc(sizeof(BSTIterator));
    result->node = (int *)malloc(10000*sizeof(int));
    result->pos = -1;
    result->length = 0;
    inorder(root, result->node, &result->length);
    return result;
}

int bSTIteratorNext(BSTIterator* obj) {
    return obj->node[++obj->pos];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->pos < obj->length - 1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->node);
    free(obj);
}


/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
