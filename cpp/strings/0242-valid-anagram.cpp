#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(t[i]) == mp.end())
            return false;
        mp[t[i]]--;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] != 0)
            return false;
    }

    return true;
}
