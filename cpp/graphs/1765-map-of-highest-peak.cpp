#include <queue>
#include <tuple>
#include <vector>

using namespace std;


vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    vector<vector<int>> height(isWater.size(), vector<int> (isWater[0].size()));
    
    queue<tuple<int, int, int>> q;
    vector<vector<int>> ways = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    
    for (int i = 0; i < isWater.size(); i++) {
        for (int j = 0; j < isWater[0].size(); j++) {
            if (isWater[i][j] == 1) q.push({i, j, 0});
        }
    }
    
    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();
        
        
        for (const auto way : ways) {
            int new_x = get<0>(cur) + way[0];
            int new_y = get<1>(cur) + way[1];

            if (new_x >= 0 && new_x < isWater.size() && new_y >= 0 && new_y < isWater[0].size() &&
                height[new_x][new_y] == 0 && isWater[new_x][new_y] == 0) {
                height[new_x][new_y] = get<2>(cur) + 1;
                q.push({new_x, new_y, get<2>(cur) + 1});
            }
        }
    }
    
    return height;
}