from typing import List

def rotate(matrix: List[List[int]]) -> None:
    for layer in range(len(matrix) // 2):
        first = layer
        last = len(matrix) - layer - 1
        for i in range(first, last):
            offset = i - first
            top = matrix[first][i]
            matrix[first][i] = matrix[last - offset][first]
            matrix[last - offset][first] = matrix[last][last - offset]
            matrix[last][last - offset] = matrix[i][last]
            matrix[i][last] = top
