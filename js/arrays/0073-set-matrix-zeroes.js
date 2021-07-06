var nullifyRow = function(matrix, row) {
    for (var i = 0; i < matrix[0].length; i++) {
        matrix[row][i] = 0;
    }
};

var nullifyColumn = function(matrix, column) {
    for (var i = 0; i < matrix.length; i++) {
        matrix[i][column] = 0;
    }
};

var setZeroes = function(matrix) {
    var hasZeroRow = false;
    var hasZeroColumn = false;
    
    for (var i = 0; i < matrix.length; i++) {
        if (matrix[i][0] == 0) {
            hasZeroColumn = true;
            break;
        }
    }
    
    for (var i = 0; i < matrix[0].length; i++) {
        if (matrix[0][i] == 0) {
            hasZeroRow = true;
            break;
        }
    }
    
    for (var i = 1; i < matrix.length; i++) {
        for (var j = 1; j < matrix[0].length; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for (var i = 1; i < matrix.length; i++) {
        if (matrix[i][0] == 0) {
            nullifyRow(matrix, i);
        }
    }
    
    
    for (var i = 1; i < matrix[0].length; i++) {
        if (matrix[0][i] == 0) {
            nullifyColumn(matrix, i);
        }
    }
    
    if (hasZeroColumn) nullifyColumn(matrix, 0);
    
    if (hasZeroRow) nullifyRow(matrix, 0);
};