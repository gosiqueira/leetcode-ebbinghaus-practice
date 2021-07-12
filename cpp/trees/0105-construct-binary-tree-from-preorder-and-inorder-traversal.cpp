#include <algorithm>
#include <vector>
#include <structures.h>

using namespace std;


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, inorder, 0, inorder.size() - 1);
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end) {
    if (start > end) return nullptr;
    
    int val = preorder[0];
    preorder.erase(preorder.begin());
    
    TreeNode* root = new TreeNode(val);
    
    if (start != end) {
        int index = find(inorder.begin() + start, inorder.begin() + end, val) - inorder.begin();
        if (index > start) root->left = build(preorder, inorder, start, index - 1);
        if (index < end) root->right = build(preorder, inorder, index + 1, end);
    }
    
    return root;
}