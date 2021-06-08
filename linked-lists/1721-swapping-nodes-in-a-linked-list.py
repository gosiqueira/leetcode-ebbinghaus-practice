from typing import ListNode


def swapNodes(head: ListNode, k: int) -> ListNode:
    list_len = 0
    cur = head
    
    while cur:
        cur = cur.next
        list_len += 1
        
    left, right = None, None
    left_idx, right_idx = k - 1, list_len - k
    
    cur = head
    cur_idx = 0

    while cur:
        if cur_idx == left_idx:
            left = cur
        if cur_idx == right_idx:
            right = cur
            
        cur = cur.next
        cur_idx += 1
        
    left.val, right.val = right.val, left.val
    
    return head