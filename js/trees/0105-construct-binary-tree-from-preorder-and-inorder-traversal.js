var buildTree = function(preorder, inorder) {
    if (preorder.length === 0 || inorder.length === 0) return undefined;
    var val = preorder.shift();
    var idx = inorder.indexOf(val);
    
    var left = undefined;
    var right = undefined
    
    if (idx > 0) left = buildTree(preorder, inorder.slice(0, idx));
    if (idx < inorder.length) right = buildTree(preorder, inorder.slice(idx + 1, inorder.length));
    
    return new TreeNode(val, left, right);
};