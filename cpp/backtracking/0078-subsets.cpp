#include <algorithm>
#include <vector>

using namespace std;

void solution(vector<int> nums, int curPos, vector<int> curComb, vector<vector<int>>& subsets) {
    subsets.push_back(curComb);
    if (curPos == nums.size()) 
        return;
    
    for (int i = curPos; i < nums.size(); i++) {
        curComb.push_back(nums[i]);
        solution(nums, i + 1, curComb, subsets);
        curComb.pop_back();
    }
}
    
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> combinations;

    vector<int> curComb;
    solution(nums, 0, curComb, combinations);

    return combinations;
}