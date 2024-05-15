// https://leetcode.com/problems/valid-sudoku/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValidSquare(vector<vector<char>>& board, int offsetj, int offsetx) {
    vector<int> count(10);
 
    for (int j = offsetj; j < offsetj + 3; ++j) {
        for (int x = offsetx; x < offsetx + 3; ++x) {
            if (board[j][x] == '.') continue;
            if (board[j][x] - '0' > 10 && board[j][x] != '.') {
                return false;
            }
            if (board[j][x] - '0' <= 9) {
                count[board[j][x] - '0']++;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (count[i] > 1) return false;
    }
    return true;
}



bool isValidRow(vector<char>& lst) {
    for (auto now : lst) {
        if (now == '.') continue;
        if (now - '0' > 10) return false;
        if (count(lst.begin(), lst.end(), now) != 1) return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for (auto row : board) {
        if (!isValidRow(row)) return false;
    }
  
    for (int index = 0; index < 9; ++index) {
        vector<char> column;
        for (auto row : board) {
            column.push_back(row[index]);
        }
        
        if (!isValidRow(column)) return false;
        
    }
    for (int offsetj = 0; offsetj <= 6; offsetj += 3) {
        for (int offsetx = 0; offsetx <= 6; offsetx += 3) {
            if (!isValidSquare(board, offsetj, offsetx)) return false;
        }
    }
   
    return true;
}


int main() {
    vector<vector<char>> board = {
        {'.','.','.','.','.','.','.','.','2'},
        {'.','5','9','.','2','.','.','.','.'},
        {'.','.','.','.','.','.','8','7','.'},
        {'.','.','.','.','.','3','5','.','.'},
        {'.','9','.','.','7','.','.','.','.'},
        {'.','8','.','.','.','.','1','6','.'},
        {'.','.','1','9','8','.','.','.','.'},
        {'.','.','.','.','9','.','.','8','.'},
        {'.','.','.','3','.','6','.','.','.'}
    };

    cout << isValidSudoku(board);
    return 0;
}