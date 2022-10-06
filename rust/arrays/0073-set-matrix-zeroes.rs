fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
    let mut zeroes: HashMap<(usize, usize), bool> = HashMap::new();
    for i in 0..matrix.len() {
        for j in 0..matrix[0].len() {
            if matrix[i][j] == 0 {
                zeroes.insert((i, j), true);
            }
        }
    }

    for (i, j) in zeroes.keys() {
        let (i, j) = (*i, *j);
        for m in 0..matrix.len() {
            matrix[m][j] = 0;
        }

        for n in 0..matrix[0].len() {
            matrix[i][n as usize] = 0;
        }
    }
}