#include <algorithm>
#include <structures.h>

using namespace std;


ListNode* swapNodes(ListNode* head, int k) {
    ListNode *cur = head;
    int len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }

    ListNode *left, *right;
    cur = head;
    int cur_idx = 1;
    while(cur) {
        if (cur_idx == k) left = cur;
        if (cur_idx == len - k + 1) right = cur;
        cur = cur->next;
        cur_idx++;
    }

    swap(left->val, right->val);
    
    return head;
}