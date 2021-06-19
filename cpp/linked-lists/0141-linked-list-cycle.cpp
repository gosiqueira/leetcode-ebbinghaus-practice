#include <structures.h>

bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    if (head && head->next) {
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
    }
    return false;
}