from structures import TreeNode


last_visited = None


def isValidBST(root: TreeNode) -> bool:
    return checkValid(root)
        
        
def checkValid(root: TreeNode) -> bool:
    global last_visited
    if root is None:
        return True
    
    if not checkValid(root.left):
        return False
    
    if last_visited and root.val <= last_visited:
        return False
    
    last_visited = root.val
    
    if not checkValid(root.right):
        return False
    
    return True