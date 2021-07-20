#include <vector>

using namespace std;


vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> not_reacheable;
    vector<int> indegree (n, 0);
    
    for (const auto edge : edges) {
        indegree[edge[1]]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            not_reacheable.push_back(i);
        }
    }
    
    return not_reacheable;
}