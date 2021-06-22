#include <structures.h>


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *curA = headA;
    ListNode *curB = headB;
    int lenA = 0;
    int lenB = 0;
    
    while (curA->next) {
        lenA++;
        curA = curA->next;
    }
    
    while (curB->next) {
        lenB++;
        curB = curB->next;
    }
    
    curA = headA;
    curB = headB;

    if (lenA > lenB) {
        for (int i = 0; i < lenA - lenB; i++) curA = curA->next; 
    }

    if (lenA < lenB) {
        for (int i = 0; i < lenB - lenA; i++) curB = curB->next;
    }
    
    while (curA && curB) {
        if (curA == curB) return curA;;
        curA = curA->next;
        curB = curB->next;
    }
    
    return nullptr;
}