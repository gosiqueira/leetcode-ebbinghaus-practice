#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> adj_list (n);
    
    for (int i = 0; i < edges.size(); i++) {
        adj_list[edges[i][0]].push_back({edges[i][1], succProb[i]});
        adj_list[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    
    priority_queue<pair<double, int>> q;
    set<int> visited;
    
    q.push({1, start});
    
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        
        if (cur.second == end) return cur.first;
        visited.insert(cur.second);
        
        for (const auto neighbor : adj_list[cur.second]) {
            if (visited.find(neighbor.first) == visited.end()) {
                q.push({cur.first * neighbor.second, neighbor.first});
            }
        }
    }
    
    return 0;
}