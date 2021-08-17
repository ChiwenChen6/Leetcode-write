/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int goodNodeElement(struct TreeNode* root, int max){
    if (root==NULL) return 0;

    if (root->val > max) max = root->val;

    if (root->val >= max)
        return 1 + goodNodeElement(root->left,max) +
               goodNodeElement(root->right,max);
    return goodNodeElement(root->left,max) +
               goodNodeElement(root->right,max);
}


int goodNodes(struct TreeNode* root){
   if (root==NULL) return 0;
    else return goodNodeElement(root,root->val);
}
