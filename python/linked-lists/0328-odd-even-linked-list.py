from typing import ListNode


def oddEvenList(head: ListNode) -> ListNode:
    odd = head
    if head:
        even = head.next
        
        cur_odd = odd
        cur_even = even
        while cur_odd.next and cur_even.next:
            cur_odd.next = cur_odd.next.next
            cur_odd = cur_odd.next
            cur_even.next = cur_even.next.next
            cur_even = cur_even.next
            
        cur_odd.next = even
        
    return odd