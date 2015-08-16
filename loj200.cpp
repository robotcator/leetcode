#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool is_inside(int x, int y, int m, int n) {
        if(x >= 0 && x < m && y >= 0 && y < n) return true;
        else return false;
    }

    void dfs(int x, int y, int m, int n, vector<vector<char>>& grid) {
        for (int i = 0; i < 4; i ++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(is_inside(nx, ny, m, n) &&
               grid[nx][ny] == '1') {
                   grid[nx][ny] = '0';
                   dfs(nx, ny, m, n, grid);
               }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); if(m == 0) return 0;
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i ++){
            for (int j = 0; j < n; j ++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                cout << i << j << "bingo" << endl;
                    dfs(i, j, m, n, grid);
                    ans ++;
                }
            }
        }
        return ans;
    }

int main() {
    vector<vector<char>> grid;
    string temp[] = {"11111011111111101011","01111111111110111110","10111001101111111111","11110111111111111111",
    "10011111111111111111","10111111011101110111","01111111111101101111","11111111111101111011",
    "11111111110111111111","11111111111111111111","01111111011111111111","11111111111111111111",
    "11111111111111111111","11111011111110111111","10111110111011110111","11111111111101111110",
    "11111111111110111100","11111111111111111111","11111111111111111111","11111111111111111111"};

    for (int i = 0; i < temp[0].size(); i ++) {
         vector<char> tmp;
        for (int j = 0; j < temp[0].size(); j ++) {
            tmp.push_back(temp[i][j]);
        }
        grid.push_back(tmp);
    }
    cout << numIslands(grid) << endl;
    return 0;
}
