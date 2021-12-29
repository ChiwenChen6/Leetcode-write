/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void left_to_right(struct Node* left, struct Node* right)
{
    if (left && right) {
        left->next = right;
        left_to_right(left->right, right->left);
    }
}

struct Node* connect(struct Node* root)
{
    if (root) {
        left_to_right(root->left, root->right);
        connect(root->left);
        connect(root->right);
    }
    return root;
}
