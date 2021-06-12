#include <map>
#include <vector>

using namespace std;


int tupleSameProduct(vector<int>& nums) {
    int response = 0;
    map<int, int> prods;
    for(int i = 0; i < nums.size(); i++) {
        for (int j  = i+1; j < nums.size(); j++) {
            prods[nums[i] * nums[j]]++;
        }
    }
    
    for(const auto& prod: prods) {
        if (prod.second >= 2) response += (prod.second * (prod.second - 1)) / 2;
    }
    
    return response * 8;
}