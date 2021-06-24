#include <queue>
#include <vector>
#include <structures.h>

using namespace std;


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> response;
    if (root == nullptr) return response;
        
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> level;
        int len = q.size();
        for (int i = 0; i < len; i++) {
            TreeNode *cur = q.front();
            q.pop();
            level.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        response.push_back(level);
    }
    
    return response;
}