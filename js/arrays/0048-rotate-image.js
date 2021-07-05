var rotate = function(matrix) {
    for (var layer = 0; layer < matrix.length / 2; layer++) {
        var first = layer
        var last = matrix.length - layer - 1
        for (var i = first; i < last; i++) {
            var offset = i - first
            
            var top = matrix[first][i]
            
            matrix[first][i] = matrix[last - offset][first]
            matrix[last - offset][first] = matrix[last][last-offset]
            matrix[last][last-offset] = matrix[i][last]
            matrix[i][last] = top
        }
    }
};