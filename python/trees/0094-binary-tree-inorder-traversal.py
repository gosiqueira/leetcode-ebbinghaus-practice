from typing import List
from structures import TreeNode


def inorderTraversal(root: TreeNode) -> List[int]:
    if root is None:
        return []
    
    output = []
    if root.left:
        output.extend(inorderTraversal(root.left))
        
    output.append(root.val)
    
    if root.right:
        output.extend(inorderTraversal(root.right))
        
    return output