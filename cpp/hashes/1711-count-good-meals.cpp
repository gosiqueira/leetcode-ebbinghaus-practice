#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int countPairs(vector<int>& deliciousness) {
    unordered_map<int, int> counter;
    int total = 0;

    for(int d: deliciousness){
        for(int i = 0; i < 22; i++){
            int p = 1 << i;
            int y = p - d;
            if(counter.count(y)) {
                total += counter[y];
                total %= 1e9 + 7;
            }
        }
        counter[d]++;
    }
    return total;
}