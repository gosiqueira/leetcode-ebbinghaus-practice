from typing import List


def numEnclaves(grid: List[List[int]]) -> int:
    rows, cols = len(grid), len(grid[0])
    
    stack = []
    for i in range(rows):
        if grid[i][0]: stack.append((i, 0))
        if grid[i][cols - 1]: stack.append((i, cols - 1))
    
    for j in range(cols):
        if grid[0][j]: stack.append((0, j))
        if grid[rows - 1][j]: stack.append((rows - 1, j))
    
    while stack: # dfs 
        i, j = stack.pop()
        grid[i][j] = 0 # mark as seen 
        for ii, jj in (i - 1, j), (i, j - 1), (i, j + 1), (i + 1, j): 
            if 0 <= ii < rows and 0 <= jj < cols and grid[ii][jj]: stack.append((ii, jj))
    
    return sum(map(sum, grid))
