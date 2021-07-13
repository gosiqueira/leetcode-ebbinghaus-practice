#include <queue>
#include <structures.h>

using namespace std;


Node* connect(Node* root) {
    if (root == nullptr) return root;
    
    queue<Node*> q;
    q.push(root);
    
    Node* prev = root;
    
    while (!q.empty()) {
        int level = q.size();
        for (int i = 0; i < level; i++) {
            Node* cur = q.front();
            q.pop();
            
            if (i > 0) {
                prev->next = cur;
            }
            prev = cur;
            
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    
    return root;
}