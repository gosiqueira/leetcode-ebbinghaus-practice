#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void solution(int n, string s, vector<string> *combinations) {
    if (s.size() == 2 * n) {
        combinations->push_back(s);
        return;
    }

    int l_par = 0, r_par = 0;
    for (auto c: s) {
        if (c == '(') l_par++;
        else r_par++;
    }

    if (l_par == r_par) 
        solution(n, s + "(", combinations);
    else if (r_par < l_par) {
        if (l_par < n) 
            solution(n, s + '(', combinations);
        solution(n, s + ')', combinations);
    }
}

vector<string> generateParenthesis(int n) {
    string s = "";
    vector<string> combinations;
    solution(n, s, &combinations);

    return combinations;
}