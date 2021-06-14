#include <limits>
#include <vector>

using namespace std;


bool increasingTriplet(vector<int>& nums) {
    int m = numeric_limits<int>::max();
    int n = numeric_limits<int>::max();
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] <= m) m = nums[i];
        else if (nums[i] <= n) n = nums[i];
        else return true;
    }
    
    return false;
}