var levelOrder = function(root) {
    var response = [];
    if (root == undefined) return response;
    
    var queue = [];
    queue.push(root);
    
    while (queue.length > 0) {
        var level = []
        var len = queue.length;
    
        for (var i  = 0; i < len; i++) {
            var cur = queue.shift();
            
            level.push(cur.val);

            if (cur.left) queue.push(cur.left);
            if (cur.right) queue.push(cur.right);
        }
        response.push(level);
    }
    
    return response;
};