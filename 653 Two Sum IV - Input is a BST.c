/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool findSum(int* arr, int k, int size)
{
    int i=0;
    int j=size-1;
    while(j>i)
    {
        if(arr[i]+arr[j]==k)
        {
            return true;
        }
        else if(arr[i]+arr[j]>k)
        {
            j--;
        }
        else 
        {
            i++;
        }
    }
    return false;
}

void inorder(struct TreeNode* root,int* arr,int* size)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,arr,size);
    arr[*size]=root->val;
    *size+=1;
    inorder(root->right,arr,size);
}

bool findTarget(struct TreeNode* root, int k){
    int* arr=malloc(10000*sizeof(int));
    int size=0;
    if(!root)
    {
        return false;
    }
    inorder(root->left,arr,&size);
    arr[size]=root->val;
    size+=1;
    inorder(root->right,arr,&size);

    return findSum(arr,k,size);
    
}


// Runtime: 28 ms, faster than 32.10% of C online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 21.1 MB, less than 17.28% of C online submissions for Two Sum IV - Input is a BST.
