#include <algorithm>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums){
    for (int lastNonZero = 0, cur = 0; cur < nums.size(); ++cur){
        if (nums[cur] != 0)
            swap(nums[lastNonZero++], nums[cur]);
    }
}