struct TreeNode* pruneTree(struct TreeNode* root)
{
    if (root->left)
        root->left = pruneTree(root->left);
    
    if (root->right)
        root->right = pruneTree(root->right);

    if (root->val == 1 || root->right || root->left)
        return (root);
    else
        return (NULL);
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Tree Pruning.
// Memory Usage: 6.4 MB, less than 38.89% of C online submissions for Binary Tree Pruning.
