from structures import ListNode

def reverseList(head: ListNode) -> ListNode:
    if head is not None:
        cur = head
        prev = None

        while cur.next:
            nxt = cur.next
            cur.next = prev

            prev = cur
            cur = nxt

        cur.next = prev

        head = cur
    return head