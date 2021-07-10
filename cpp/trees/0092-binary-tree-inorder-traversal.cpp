#include <vector>
#include <structures.h>

using namespace std;


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> response;
    traverse(root, &response);
    
    return response;
}

void traverse(TreeNode* root, vector<int>* response) {
    if (root) {
        if (root->left) traverse(root->left, response);

        (*response).push_back(root->val);

        if (root->right) traverse(root->right, response);
    }
}