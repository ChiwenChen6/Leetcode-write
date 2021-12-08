/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int tree;
int findTilt(struct TreeNode* root) {
  tree=0;
	node_sum(root);
	return(tree);
}
int node_sum(struct TreeNode *root) {
  int node,left_sum = 0, right_sum = 0;
	if (root != NULL)	{
		left_sum = node_sum(root->left);
		right_sum = node_sum(root->right);
		node = abs(left_sum - right_sum);
		tree+=node;
		return(root->val + left_sum + right_sum);
	}
	else
		return(0);
}
