fn rotate(matrix: &mut Vec<Vec<i32>>) {
    for row in 0..matrix.len() {
        let (first, last) = (row, matrix.len() - row - 1);
        for i in first..last {
            let offset = i - first;
            let top = matrix[first][i];

            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}