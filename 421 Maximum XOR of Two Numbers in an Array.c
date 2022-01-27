#define MAX_BIT 30
struct tree{
    struct tree *leaf[2];
};

static void buildTree(struct tree *root, int *nums, int numsSize)
{
    int i;
    int j;
    int bit_val;
    struct tree *node = NULL;

    for (i = 0; i < numsSize; i++) {
        node = root;
        for (j = MAX_BIT; j >= 0; j--) {
            bit_val = nums[i] >> j & 1;
            if (!node->leaf[bit_val])
                node->leaf[bit_val] = calloc(1, sizeof(*root));
            node = node->leaf[bit_val];
        }
    }
}

void freeTree(struct tree *root) {
    if (!root)
        return;
    
    if (root->leaf[0]);{
        freeTree(root->leaf[0]);
    }
    if (root->leaf[1]){
        freeTree(root->leaf[1]);
    }
    free(root);
}

int findMaximumXOR(int* nums, int numsSize){
    struct tree root = {0};
    int i;
    int j;
    struct tree *node = NULL;
    int max = 0;
    int cur = 0;
    int bit_val = 0;
    if (1 == numsSize){
        return 0;
    }
    buildTree(&root, nums, numsSize);

    for (i = 0; i < numsSize; i++) {
        cur = 0;
        node = &root;
        for (j = MAX_BIT; j >= 0; j--) {
            bit_val = nums[i] >> j & 1;
            if (node->leaf[!bit_val]) {
                cur += 1 << j;
                node = node->leaf[!bit_val];
            } else {
                node = node->leaf[bit_val];
            }
        }

        if (cur > max){
            max = cur;
        }
    }

    freeTree(root.leaf[0]);
    freeTree(root.leaf[1]);
    return max;
}
