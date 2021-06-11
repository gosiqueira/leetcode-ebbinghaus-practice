#include <vector>

using namespace std;

void nullifyRow(vector<vector<int>>& matrix, int row) {
    for(int i = 0; i < matrix[row].size(); i++) {
        matrix[row][i] = 0;
    }
}

void nullifyColumn(vector<vector<int>>& matrix, int col) {
    for(int i = 0; i < matrix.size(); i++) {
        matrix[i][col] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    bool hasZeroRow = false;
    bool hasZeroCol = false;
    for(int i = 0; i < matrix.size(); i++) {
        if(matrix[i][0] == 0) {
            hasZeroCol = true;
            break;
        }
    }
    for(int i = 0; i < matrix[0].size(); i++) {
        if (matrix[0][i] == 0) {
            hasZeroRow = true;
            break;
        }
    }
    
    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 1; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for(int i = 1; i < matrix.size(); i++) {
        if(matrix[i][0] == 0) {
            nullifyRow(matrix, i);
        }
    }
    
    for(int i = 1; i < matrix[0].size(); i++) {
        if(matrix[0][i] == 0) {
            nullifyColumn(matrix, i);
        }
    }
    
    if (hasZeroRow) {
        nullifyRow(matrix, 0);
    }
    if (hasZeroCol) {
        nullifyColumn(matrix, 0);
    }  
}
