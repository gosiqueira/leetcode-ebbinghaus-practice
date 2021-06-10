#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> response;
    sort(nums.begin(), nums.end());
        
    for(int i=0; i < nums.size(); i++) {
        int n = nums[i];
        if (i > 0 && n == nums[i-1]) {
            continue;
        }
        
        int l = i + 1;
        int r = nums.size() - 1;
        while (l<r) {
            int sum = n + nums[l] + nums[r];
            if (sum > 0) {
                r--;
            }
            else if (sum < 0) {
                l++;
            }
            else {
                vector<int> match({n, nums[l++], nums[r]});
                response.push_back(match);
                while (nums[l] == nums[l-1] && l < r) {
                    l++;
                }
            }
        }
    }
    
    return response;
}