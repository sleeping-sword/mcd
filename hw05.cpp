#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

bool sameRow(int i, int j) { return (i/9 == j/9); }
bool sameCol(int i, int j) { return ((i-j) % 9 == 0); }
bool sameBlock(int i, int j) { return (i/27 == j/27 && i%9/3 == j%9/3); }

vector<string> solveSudoku(string board) {
    vector<string> ans;
    int idx = board.find('.');
    if(idx == string::npos) { // If solved
        return {board};
    }

    unordered_set<char> exclude;
    for(int j=0; j<81; j++) {
        if(sameRow(idx, j) || sameCol(idx, j) || sameBlock(idx, j)) {
            exclude.insert(board[j]);
        }
    }

    for(char m='1'; m<='9'; m++) {
        if(exclude.find(m) == exclude.end()) { // if m is not in exclude
            string new_board = board;
            new_board[idx] = m;
            auto new_ans = solveSudoku(new_board);
            ans.insert(ans.end(), new_ans.begin(), new_ans.end());
        }
    }
    return ans
};