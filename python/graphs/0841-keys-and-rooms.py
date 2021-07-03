from collections import deque
from typing import List


def canVisitAllRooms(rooms: List[List[int]]) -> bool:
    keys = set({0})
    visited = set()
    
    queue = deque([0])
    
    while queue:
        cur = queue.popleft()
        cur_keys = rooms[cur]
        keys.update(cur_keys)
        
        if cur in keys:
            visited.add(cur)
            
        for key in cur_keys:
            if key not in visited:
                queue.append(key)

    return len(rooms) == len(visited)