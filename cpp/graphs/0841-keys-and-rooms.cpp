#include <queue>
#include <set>
#include <vector>

using namespace std;


bool canVisitAllRooms(vector<vector<int>>& rooms) {
    set<int> keys;
    set<int> visited;
    
    queue<int> q;
    
    keys.insert(0);
    q.push(0);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        vector<int> k = rooms[cur];
        for (int key : k) {
            keys.insert(key);
        }
        
        if (keys.find(cur) != keys.end()) {
            visited.insert(cur);
        }
        
        for (auto key : rooms[cur]) {
            if (visited.find(key) == visited.end()) {
                q.push(key);
            }
        }
    }
    
    return rooms.size() == visited.size();
}