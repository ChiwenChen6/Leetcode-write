
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int **a = malloc(sizeof(int *[512]));
    int *c = *returnColumnSizes = malloc(sizeof(int [512]));
    int k = 0;
    int f = 0;
    int ln = 1; 
    int lb; 
    int i; 
    int l;
    for (struct Node *n[10000] = { root }, **p ; root && f < ln ; k++){
        for (a[k] = malloc(sizeof(int [c[k] = (lb = ln) - f])), i = 0 ; f < lb ; f++){
            for (a[k][i++] = n[f]->val, l = n[f]->numChildren, p = n[f]->children ; l-- ; n[ln++] = *p++);
        }
    }
    return *returnSize = k, a;
}
