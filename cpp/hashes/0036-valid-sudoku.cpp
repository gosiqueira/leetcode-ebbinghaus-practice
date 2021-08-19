#include <unordered_set>
#include <vector>

using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<int> row[9];
    unordered_set<int> col[9];
    unordered_set<int> box[9];
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            char val = board[i][j];
            int box_index = (i/3) * 3 + (j/3);
        
            if(val != '.'){
                if(row[i].find(val) != row[i].end( ) || col[j].find(val) != 
                    col[j].end( ) || box[box_index].find(val) != box[box_index].end( )){
                    return false;;
                }

                row[i].insert(val);
                col[j].insert(val);
                box[box_index].insert(val);
            }
        }
    }

    return true;
}