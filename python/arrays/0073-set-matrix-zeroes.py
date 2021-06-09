from typing import List


def setZeroes(matrix: List[List[int]]) -> None:
    """
    Do not return anything, modify matrix in-place instead.
    """
    zeroes = {}
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 0:
                zeroes[(i, j)] = True
                
    for i, j in zeroes.keys():
        for m in range(len(matrix)):
            matrix[m][j] = 0
        for n in range(len(matrix[0])):
            matrix[i][n] = 0