var addTwoNumbers = function(l1, l2) {
    return add(l1, l2, 0);
};

var add = function(l1, l2, carry) {
    if (l1 === null && l2 === null && carry === 0) return null;
    
    var val = carry;
    if (l1 !== null) {
        val += l1.val;
    }
    
    if (l2 !== null) {
        val += l2.val;
    }
    
    return {
        val: val % 10,
        next: add(l1 !== null ? l1.next : null,
            l2 !== null ? l2.next : null,
            val > 9 ? 1 : 0
        )
    };
}