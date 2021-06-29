from collections import deque
from typing import List


def highestPeak(isWater: List[List[int]]) -> List[List[int]]:
    height = [[0 for _ in range(len(isWater[0]))] for _ in range(len(isWater))]
    ways_x, ways_y = [-1, 1, 0, 0], [0, 0, 1, -1]
    
    queue = deque()
    
    for i in range(len(isWater)):
        for j in range(len(isWater[0])):
            if isWater[i][j] == 1:
                queue.append((i, j, 0))
                
    while queue:
        x, y, h = queue.popleft()

        for delta_x, delta_y in zip(ways_x, ways_y):
            new_x, new_y = x + delta_x, y + delta_y
            if 0 <= new_x < len(isWater) and 0 <= new_y < len(isWater[0]) and height[new_x][new_y] == isWater[new_x][new_y] == 0:
                height[new_x][new_y] = h + 1
                queue.append((new_x, new_y, h + 1))
                            
    return height