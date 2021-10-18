/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int xDepth;
int yDepth;
int parx;       
int pary;       
void searchCousins(struct TreeNode* root, int x, int y, int deep, int p){
    if (root == NULL){
        return ;
    }
    if (root->val == x){
        xDepth = deep;
        parx = p;
    }
    if (root->val == y){
        yDepth = deep;
        pary = p;
    }
     searchCousins(root->left, x, y, deep + 1, root->val);
     searchCousins(root->right, x, y, deep + 1, root->val);
}

bool isCousins(struct TreeNode* root, int x, int y){
    pary = parx = xDepth = yDepth = 0;
    searchCousins(root, x, y, 1, root->val);
    if (pary == parx)      
        return false;
    if (xDepth  == yDepth)
        return true;
    return false;
}


// Runtime: 4 ms, faster than 34.48% of C online submissions for Cousins in Binary Tree.
// Memory Usage: 6.4 MB, less than 24.14% of C online submissions for Cousins in Binary Tree.

