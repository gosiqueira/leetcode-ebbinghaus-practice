var connect = function(root) {
    if (root === null) return null;
    var queue = [root];
    
    while(queue.length > 0) {
        lvl_sz = queue.length;
        
        var prev = null;
        for (var i = 0; i < lvl_sz; i++) {
            var cur = queue.shift();
            
            if (i !== 0 && prev !== null) {
                prev.next = cur;
            }
            prev = cur;
            
            if (cur !== null) queue.push(cur.left);
            if (cur !== null) queue.push(cur.right);
        }
    }
    
    return root;
};