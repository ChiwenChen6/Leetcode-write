
"""
Created on Tues Nov. 10 19:29 2020
Old version and rewrite here
@author: Chiwen Chen
"""



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



int kthSmallest(struct TreeNode* root, int k){
    int count = k;
    int eletval = 0;
    
    flatten(&count, &eletval, root);
    return eletval;
}

void flatten(int *count, int *eletval, struct TreeNode *node){
    if (node == NULL) 
    { 
        return; 
    } 
    flatten(count, eletval, node->left);
    
    *count -= 1; 
    
    if (*count == 0) {
        *eletval = node->val; return; 
    } 
    flatten(count, eletval, node->right); 
}

"""
Runtime: 8 ms, faster than 96.69% of C online submissions for Kth Smallest Element in a BST.
Memory Usage: 10.2 MB, less than 16.02% of C online submissions for Kth Smallest Element in a BST.
"""