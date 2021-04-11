/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(A, B) (A) > (B) ? (A) : (B)


int deepestLeavesSum(struct TreeNode* root) {
    int sum = 0;
    int maxDepth = 0;
    findDepthOfTree(root, &maxDepth, 0);
    inorder(root, &sum, maxDepth, 0);;
    return sum;
}

int is_leaf(struct TreeNode* node) {
    return (node->left == NULL && node->right == NULL);
}

void inorder(struct TreeNode* node, int* sum, int maxDepth, int depth) {
    if (node == NULL) {
        return;
    }
    inorder(node->left, sum, maxDepth, depth + 1);
    if (is_leaf(node) && depth == maxDepth){
        *sum += node->val;
    }
    inorder(node->right, sum, maxDepth, depth + 1);
}


void findDepthOfTree(struct TreeNode* node, int* maxDepth, int currentDepth) {
    if (node == NULL) {
        return;
    }
    *maxDepth = MAX(*maxDepth, currentDepth);
    findDepthOfTree(node->left, maxDepth, currentDepth + 1);
    findDepthOfTree(node->right, maxDepth, currentDepth + 1);
}


// Runtime: 16 ms, faster than 96.61% of C online submissions for Deepest Leaves Sum.
// Memory Usage: 15.9 MB, less than 42.37% of C online submissions for Deepest Leaves Sum.
