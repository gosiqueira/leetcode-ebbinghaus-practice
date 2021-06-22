#include <structures.h>

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return addLists(l1, l2, 0);
}

ListNode *addLists(ListNode *l1, ListNode *l2, int carry) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
        return nullptr;
    }
    
    int val = carry;
    if (l1 != nullptr) {
        val += l1->val;
    }
    
    if (l2 != nullptr) {
        val += l2->val;
    }
    
    ListNode *result = new ListNode(val % 10);
    
    result->next = addLists(l1 != nullptr ? l1->next : nullptr,
                            l2 != nullptr ? l2->next : nullptr,
                            val > 9 ? 1 : 0);

    return result;
}