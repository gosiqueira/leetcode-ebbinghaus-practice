from typing import List


def dfs(self, board, word, visited, idx, row, col):
    if not (0 <= row < len(board) and 0 <= col < len(board[0])):
        return False
    
    if (row, col) in visited: return False
    if board[row][col] != word[idx]: return False
    
    if idx == len(word) - 1: return True
    
    visited.add((row, col))

    for x, y in self.direction:
        dx, dy = x + row, y + col
        if self.dfs(board, word, visited, idx + 1, dx, dy):
            return True
        
    visited.remove((row, col))
        
    return False


def exist(self, board: List[List[str]], word: str) -> bool:
    self.direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    visited = set()
    for i in range(len(board)):
        for j in range(len(board[0])):
            if self.dfs(board, word, visited, 0, i, j):
                return True
    
    return False