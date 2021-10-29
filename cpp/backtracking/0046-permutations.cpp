#include <algorithm>
#include <vector>

using namespace std;

void permuting(vector<int> nums, int i, int n, vector<vector<int>> &permutations){
    if (i == n - 1){
        permutations.push_back(nums);
        return;
    }
    
    for (int j = i; j < n; ++j){
        // Swap characters for the permutations
        swap(nums[i], nums[j]);
        
        // Recursive call for subtring[i+1 - n-1]
        permuting(nums, i+1, n, permutations);
        
        // Backtrack and restore the original string
        swap(nums[i], nums[j]);
    }
}
    
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    permuting(nums, 0, nums.size(), permutations);
    
    return permutations;
}