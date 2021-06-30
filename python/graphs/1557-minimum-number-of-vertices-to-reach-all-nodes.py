from typing import List


def findSmallestSetOfVertices(n: int, edges: List[List[int]]) -> List[int]:
    reachebles = set()
    for edge in edges:
        _, node = edge
        reachebles.add(node)
        
    response = []
    for i in range(n):
        if i not in reachebles:
            response.append(i)
            
    return response