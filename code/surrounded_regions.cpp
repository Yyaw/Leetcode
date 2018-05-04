#include <iostream>
#include "data.h"
<<<<<<< HEAD
=======
#include "util/readData.h"
>>>>>>> 72ad4336086589343fb17fa5332fdb0a8c85986a

using namespace std;

class Solution {
public:
<<<<<<< HEAD
    
=======
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int row = board.size();
        int col = board[0].size();
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (i == 0 || i == row-1 || j == 0 || j == col - 1) {
                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'O') {
            board[x][y] = '#';
        }
        if (x > 0 && board[x-1][y] == 'O') {
            dfs(board, x-1, y);
        }
        if (x < board.size() - 1 && board[x+1][y] == 'O') {
            dfs(board, x+1, y);
        }
        if (y > 0 && board[x][y-1] == 'O') {
            dfs(board, x, y-1);
        }
        if (y < board[0].size() - 1 && board[x][y+1] == 'O') {
            dfs(board, x, y+1);
        }
    }
>>>>>>> 72ad4336086589343fb17fa5332fdb0a8c85986a
};

int main(int argc, char **argv)
{
    Solution s;
<<<<<<< HEAD
    return 0;
}
=======
    vector<vector<char>> data = readCharVector(argv[1]);
    s.solve(data);
    for (int i=0; i<data.size(); i++) {
        for (int j=0; j<data[0].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
>>>>>>> 72ad4336086589343fb17fa5332fdb0a8c85986a
