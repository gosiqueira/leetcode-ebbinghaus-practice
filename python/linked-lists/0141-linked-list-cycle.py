from structures import ListNode

def hasCycle(head: ListNode) -> bool:
    fast = head
    slow = head
    
    if head:
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
            
            if fast == slow:
                return True
        
    return False