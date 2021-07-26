var oddEvenList = function(head) {
    if (head === null) return head;
    
    var odd = head;
    var even = head.next;
    var evenHead = head.next;
    
    while (odd.next !== null && even.next !== null) {
        odd.next = even.next;
        even.next = odd.next.next;
        odd = odd.next;
        even = even.next;
    }
    
    odd.next = evenHead;
    
    return head;
};