from collections import deque

from structures import Node


def connect(root: Node) -> Node:
    if root is None: return None
    
    queue = deque([root])
    while queue:
        prev = root
        for i in range(len(queue)):
            cur = queue.popleft()
            
            if i != 0:
                prev.next = cur
            prev = cur
            
            if cur.left: queue.append(cur.left)
            if cur.right: queue.append(cur.right)
                
    return root