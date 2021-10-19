#include <algorithm>
#include <structures.h>

using namespace std;

ListNode* reverseList(ListNode *head){
    if (head == NULL)
        return head;

    ListNode *prev = NULL;
    ListNode *cur = head;

    while (cur != NULL){
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    head = prev;
    return head;
}