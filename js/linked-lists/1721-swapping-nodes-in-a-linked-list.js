var swapNodes = function(head, k) {
    var len = 0;
    var cur = head;
    while (cur) {
        cur = cur.next;
        len++;
    }
    
    var left = null;
    var right = null;
    var idx = 0;
    cur = head;
    for (var idx = 0; idx < len; idx++) {
        if (idx == k - 1) left = cur;
        if (idx == len - k) right = cur;
        cur = cur.next;
    }
    
    [left.val, right.val] = [right.val, left.val];
    
    return head;
};