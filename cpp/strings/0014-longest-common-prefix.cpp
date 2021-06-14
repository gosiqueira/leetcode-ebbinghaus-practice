#include <algorithm>
#include <vector>
#include <string>

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    vector<int> sizes;
    string response = "";
    for (const auto& str: strs) sizes.push_back(str.size());
    auto min_size = *min_element(sizes.begin(), sizes.end());
    for (int i = 0; i < min_size; i++) {
        char cmp = strs[0][i];
        bool valid = true;
        for (int j = 1; j < strs.size(); j++) {
            if (strs[j][i] != cmp) valid = false;
        }
        if (valid) response += cmp;
        else break;
    }
    
    return response;
}