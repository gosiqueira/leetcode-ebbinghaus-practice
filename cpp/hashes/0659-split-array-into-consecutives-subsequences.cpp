#include <queue>
#include <vector>

using namespace std;


bool isPossible(vector<int>& nums) {
    int n = nums.size(), i, j;
    int mi = nums[0], ma = nums[n-1];
    
    queue<int> q;
    vector<int> count(ma - mi + 2, 0);
    
    for(i = 0; i < n; ++i) {
        count[nums[i] - mi]++;
    }
    
    int prev = 0, cur, start;
    for(i = 0; i < ma - mi + 2; ++i) {
        cur = count[i];
        if (cur > prev) {
            for(j = 0; j < cur - prev; ++j) {
                q.push(i); 
            }
        } else if (cur < prev) {
            for(j = 0; j < prev - cur; ++j) {
                start = q.front();
                q.pop();
                if (i-start < 3) return false;
            }
        }
        prev = cur;
    }
    
    return true;  
}