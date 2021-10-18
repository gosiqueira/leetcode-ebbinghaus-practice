#include <structures.h>

using namespace std;

TreeNode * invertTree(TreeNode *root)
{
    if (!root)
        return root;
    if (!root->left && !root->right)
        return root;
    TreeNode *aux = root->left;
    root->left = root->right;
    root->right = aux;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}