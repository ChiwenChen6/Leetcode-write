/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sum;
void sumRootToLeaf_(struct TreeNode* root, int parentVal){
    if(root->left == NULL && root->right == NULL)
        sum += (parentVal << 1) + root->val;
    else{
        if(root->left)
            sumRootToLeaf_(root->left, (parentVal << 1) + root->val);
        if(root->right)
            sumRootToLeaf_(root->right, (parentVal << 1) + root->val);
    }
}

int sumRootToLeaf(struct TreeNode* root){
    sum = 0;
    if(root->left == NULL && root->right == NULL)
        sum += root->val;
    else{
        if(root->left)
            sumRootToLeaf_(root->left, root->val);
        if(root->right)
            sumRootToLeaf_(root->right, root->val);
    }
    
    return sum;
}
