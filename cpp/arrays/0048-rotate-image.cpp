#include <vector>

void rotate(vector<vector<int>>& matrix) {
    for(int layer = 0; layer < matrix.size() / 2; layer++) {
        int first = layer;
        int last = matrix.size() - layer - 1;
        for(int i = first; i < last; i++) {
            int offset = i - first;
            
            int top = matrix[first][i];
            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}