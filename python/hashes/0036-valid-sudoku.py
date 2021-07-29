from typing import List


def isValidSudoku(self, board: List[List[str]]) -> bool:
    rows = defaultdict(list)
    cols = defaultdict(list)
    blocks = defaultdict(list)

    for i in range(9):
        for j in range(9):
            if board[i][j] != '.':
                if board[i][j] not in rows[i] and board[i][j] not in cols[j] and board[i][j] not in blocks[(i//3, j//3)]:
                    rows[i].append(board[i][j])
                    cols[j].append(board[i][j])
                    blocks[(i//3, j//3)].append(board[i][j])
                else:
                    return False
                
    return True