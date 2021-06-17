#include <algorithm>
#include <string>

using namespace std;


string countAndSay(int n) {
    string response = "";
    if (n == 1) return "1";
    if (n == 2) return "11";
    
    string say = countAndSay(n - 1);
    int i = 0;
    
    while (i < say.length()) {
        int count  = 0;
        char cur = say.at(i);
        while(i < say.length() && say.at(i) == cur) {
            count++;
            i++;
        }
        
        response.push_back(count + '0');
        response.push_back(cur);
    }
    
    return response;
}