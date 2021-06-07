from structures import ListNode


def getIntersectionNode(headA: ListNode, headB: ListNode) -> ListNode:
    lenA, lenB = 0, 0
    curA, curB = headA, headB
    
    while curA.next:
        curA = curA.next
        lenA += 1
        
    while curB.next:
        curB = curB.next
        lenB += 1
        
    curA, curB = headA, headB
    
    if lenA < lenB:
        for _ in range(lenB - lenA):
            curB = curB.next
            
    if lenA > lenB:
        for _ in range(lenA - lenB):
            curA = curA.next
            
    while curA and curB:
        if curA == curB:
            return curA
        
        curA = curA.next
        curB = curB.next
        
    return None
                