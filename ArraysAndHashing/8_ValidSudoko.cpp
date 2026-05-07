#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for(int i = 0; i < 9; i++){
            vector<bool> vec(9, false);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(vec[board[i][j] - '0']) return false;
                    vec[board[i][j] - '0'] = true;
                }
            }
        }
        // column
        for(int j = 0; j < 9; j++){
            vector<bool> vec(9, false);
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    if(vec[board[i][j] - '0']) return false;
                    vec[board[i][j] - '0'] = true;
                }
            }
        }
        // box
        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){
                vector<bool> vec(9, false);
                for(int i = row; i < row+3; i++){
                    for(int j = col; j < col+3; j++){
                        if(board[i][j] != '.'){
                            if(vec[board[i][j] - '0']) return false;
                            vec[board[i][j] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Solution sol;

    vector<vector<char>> board =
{
    {'1','2','.','.','3','.','.','.','.'},
    {'4','.','.','5','.','.','.','.','.'},
    {'.','9','8','.','.','.','.','.','3'},
    {'5','.','.','.','6','.','.','.','4'},
    {'.','.','.','8','.','3','.','.','5'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','.','.','.','.','.','2','.','.'},
    {'.','.','.','4','1','9','.','.','8'},
    {'.','.','.','.','8','.','.','7','9'}
};
    sol.isValidSudoku(board)? cout<<"true"<<endl : cout<<"false"<<endl;

    return 0;
}