from structures import ListNode

def isPalindrome(head: ListNode) -> bool:
        stack  = []
        fast = head
        slow = head
        while fast and fast.next:
            stack.append(slow.val)
            fast = fast.next.next
            slow = slow.next
            
        # Has odd number of elements, skipping middle one
        if fast:
            slow = slow.next
            
        while slow:
            top = stack.pop()
            
            if top != slow.val:
                return False
            
            slow = slow.next
                
        return True