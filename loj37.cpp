#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool row[10][10], col[10][10], grid[10][10];

bool dfs(vector<vector<char> >& board, int x, int y) {
    if(x == (int)board.size() && y == (int)board[0].size()) {
        return true;
    }else{
        //cout << x << " prev " << y << endl;
        for(; x < (int)board.size(); x ++) {
            int flag = 1;
            for (; y < (int)board[0].size(); y ++) {
               if(board[x][y] == '.') {
                    flag = 0;
                    break;
               }
            }
            if(!flag) break;
            else y = 0;
        }
        if(x >= 9) return true;

        //cout << x << " blank " << y << endl;

        for (int i = 1; i <= 9; i ++) {
            //cout << row[x][i] << col[y][i] << grid[x/3*3+y/3][i] << endl;
            if(!row[x][i] && !col[y][i] && !grid[x/3*3+y/3][i]) {
                board[x][y] = i+'0';
                row[x][i] = true; col[y][i] = true;
                grid[x/3*3+y/3][i] = true;
                if(dfs(board, x, y)) return true;
                board[x][y] = '.';
                row[x][i] = false; col[y][i] = false;
                grid[x/3*3+y/3][i] = false;
            }
        }
        return false;
    }
}

void solveSudoku(vector<vector<char> >& board) {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(row));
    memset(grid, 0, sizeof(row));
    for (int i = 0; i < (int)board.size(); i ++) {
        for (int j = 0; j < (int)board[i].size(); j ++) {
          //  cout << board[i][j] ;
            if(board[i][j] != '.') {
                row[i][board[i][j]-'0'] = 1;
                col[j][board[i][j]-'0'] = 1;
                grid[i/3*3+j/3][board[i][j]-'0'] = 1;
            }
        }
       // cout << endl;
    }
    dfs(board, 0, 0);
}

int main() {
    vector<vector<char> > board;
    vector<char> v;
    char x;
    for (int i = 0; i < 9; i ++) {
        v.clear();
        for (int j = 0; j < 9; j ++) {
            scanf("%c", &x);
            v.push_back(x);
        }
        getchar();
        board.push_back(v);
    }

    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            cout << board[i][j] ;
        }
        cout << endl;
    }

    solveSudoku(board);

    cout << "last " << endl;

     for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            cout << board[i][j] ;
        }
        cout << endl;
    }


    return 0;
}
