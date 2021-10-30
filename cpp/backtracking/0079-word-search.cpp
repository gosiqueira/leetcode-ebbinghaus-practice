#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int directions[4][2] = {{1, 0}, {-1, 0},
                            {0, 1}, {0, -1}};

bool searchInGrid(vector<vector<char>>& board, pair<int,int> gridPos, string& word) { 
    if (!word.length())
        return true;

    int rowLen = board.size(), colLen = board[0].size();
    bool isOutOfBounds = gridPos.first < 0 or gridPos.second < 0 or gridPos.first >= rowLen or gridPos.second >= colLen;
    if (isOutOfBounds or word[0] != board[gridPos.first][gridPos.second])
        return false;

    char curLetter = board[gridPos.first][gridPos.second];
    board[gridPos.first][gridPos.second] = ' ';

    string nextWord = word.substr(1);
    bool exists;
    for (int i = 0; i < 4; i++) {
        pair<int, int> newPos = {gridPos.first + directions[i][0], gridPos.second + directions[i][1]};

        exists = searchInGrid(board, newPos, nextWord);
        if (exists) return exists;
    }
    board[gridPos.first][gridPos.second] = curLetter;

    return exists;
}

bool exist(vector<vector<char>>& board, string word) {
    bool exists = false;
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (searchInGrid(board, {i, j}, word))
                return true;

    return false;
}