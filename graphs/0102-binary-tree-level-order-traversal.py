from collections import deque
from typing import List


from structures import TreeNode


def levelOrder(root: TreeNode) -> List[List[int]]:
    if root is None: return []
    
    queue, response = deque([root]), []
    
    while queue:
        level = []
        for i in range(len(queue)):
            node = queue.popleft()
            level.append(node.val)
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)
                
        response.append(level)
        
    return response
