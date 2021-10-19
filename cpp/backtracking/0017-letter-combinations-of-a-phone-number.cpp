#include <algorithm>

using namespace std;

vector<string> letterCombination(const vector<int> numbers, vector<string> map, int n){
    vector<string> list;
    
    queue<string> q;
    q.push("");
    
    while (!q.empty()){
        string cur = q.front();
        q.pop();
        
        if (cur.length() == n)
            list.push_back(cur);
        else
            for (auto letter : map[numbers[cur.length()]])
                q.push(cur + letter);
    } 
    
    return list;
}

vector<string> letterCombinations(string digits) {
    vector<string> map = { "0",   "1",   "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    vector<int> numbers;
    for (auto letter : digits)
        numbers.push_back(int(letter) - int('0'));
    
    if (numbers.empty()){
        vector<string> empty;
        return empty;   
    }
    
    vector<string> combinations = letterCombination(numbers, map, digits.size());
    
    return combinations;
}