var getIntersectionNode = function(headA, headB) {
    var lenA = 0;
    var curA = headA;
    while (curA) {
        curA = curA.next;
        lenA++;
    }
    
    var lenB = 0;
    var curB = headB;
    while (curB) {
        curB = curB.next;
        lenB++;
    }
    
    curA = headA;
    curB = headB
    
    if (lenA > lenB) {
        for (var i = 0; i < lenA - lenB; i++) {
            curA = curA.next;
        }    
    } else if (lenB > lenA) {
        for (var i = 0; i < lenB - lenA; i++) {
            curB = curB.next;
        }
    }
    
    while (curA && curB) {
        if (curA === curB) {
            return curA;
        }
        curA = curA.next;
        curB = curB.next;
    }
    
    return null;
};