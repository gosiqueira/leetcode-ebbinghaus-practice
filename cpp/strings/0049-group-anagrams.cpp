#include<bits/stdc++.h>

using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;
    for (const auto& str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        anagrams[key].push_back(str);
    }
    
    vector<vector<string>> response;
    for (const auto& anagram: anagrams) { 
        response.push_back(anagram.second);
    }
    
    return response;
}