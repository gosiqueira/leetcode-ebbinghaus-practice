#include <structures.h>

ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = head;
    if (head != nullptr) {
        ListNode* evenHead = head->next;
        ListNode* even = head->next;
        while (odd->next && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
    }
        
    return head;
}