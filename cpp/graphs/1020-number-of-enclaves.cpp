#include <stack>
#include <utility>
#include <vector>

using namespace std;


int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    stack<pair<int, int>> s;
    
    for (int i = 0; i < m; i++) {
        if (grid[i][0]) s.push({i, 0});
        if (grid[i][n-1]) s.push({i, n-1});
    }
    
    for (int i = 0; i < n; i++) {
        if (grid[0][i]) s.push({0, i});
        if (grid[m-1][i]) s.push({m-1, i});
    }
    
    while (!s.empty()) {
        pair<int, int> cur = s.top();
        s.pop();
        
        int i = cur.first, j = cur.second;
        grid[i][j] = 0;
        
        for (auto neighbor : vector<vector<int>>({{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}})) {
            int ii = neighbor[0], jj = neighbor[1];
            if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj]) s.push({ii, jj});
        }
    }
    
    int sum = 0;
    for (auto row : grid) {
        for (auto col : row) {
            sum += col;
        }
    }
    
    return sum;
}