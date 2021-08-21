#include <unordered_map>
#include <vector>

using namespace std;


int maxOperations(vector<int>& nums, int k) {
    int max_op = 0;
    unordered_map<int, int> mp;
    
    for (auto n : nums) {
        if (mp[n] > 0) {
            mp[n]--;
            max_op++;
        } else {
            mp[k - n]++;
        }
    }
    
    return max_op;
}