use std::collections::HashSet;

impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        fn dfs(board: &[Vec<char>], word: &[char], visited: &mut HashSet<(i32, i32)>, i: usize, row: i32, col: i32) -> bool {
            let row_in_range = 0 <= row && row < board.len() as i32;
            let col_in_range = 0 <= col && col < board[0].len() as i32;
            if !row_in_range || !col_in_range  {
                return false;
            }

            if visited.contains(&(row, col)) {return false};
            let cur = board[row as usize][col as usize];
            if cur != word[i] {return false};

            if i == word.len()-1 {return true};

            visited.insert((row, col));

            let directions = [(1, 0), (-1, 0), (0, 1), (0, -1)];
            for (x, y) in directions {
                let (dx, dy) = (x+row, y+col);
                if dfs(board, word, visited, i+1, dx, dy) {
                    return true;
                }
            }

            visited.remove(&(row,col));

            return false;
        }

        let mut visited = HashSet::new();
        let word_chars = word.chars().collect::<Vec<char>>();
        for i in 0..board.len() {
            for j in 0..board[0].len() {
                if dfs(&board, &word_chars, &mut visited, 0, i as i32, j as i32) {
                    return true;
                }
            }
        }

        false
    }
}