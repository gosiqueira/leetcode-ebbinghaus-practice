import heapq

from collections import defaultdict
from typing import List


def maxProbability(n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
    graph = defaultdict(list)

    for i in range(len(edges)):
        graph[edges[i][0]].append([edges[i][1], succProb[i]])
        graph[edges[i][1]].append([edges[i][0], succProb[i]])
        
    probs = [[-1, start]]
    
    heapq.heapify(probs)
    visited = set()
    
    while probs:
        cur_prob, cur = heapq.heappop(probs)
        visited.add(cur)
        
        if cur == end:
            return -1 * cur_prob
        for neighbor in graph[cur]:
            if neighbor[0] not in visited:
                heapq.heappush(probs, [cur_prob * neighbor[1], neighbor[0]])

    return 0