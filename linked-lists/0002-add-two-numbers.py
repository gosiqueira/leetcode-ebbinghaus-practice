from typing import ListNode


def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    return addLists(l1, l2, 0)

def addLists(l1: ListNode, l2: ListNode, carry: int) -> ListNode or None:
    if l1 is None and l2 is None and carry == 0:
        return None
    
    result = ListNode()
    val = carry
    if l1:
        val += l1.val
    if l2:
        val += l2.val
        
    result.val = val % 10
    
    if l1 or l2:
        nxt = addLists(
            l1.next if l1 else None,
            l2.next if l2 else None,
            1 if val > 9 else 0
        )
        
        result.next = nxt
        
    return result