#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_inside(int x, int y, int m, int n) {
    if(x >= 0 && x < m && y >= 0 && y < n) return true;
    else return false;
}

bool bfs(vector<vector<char> >& board, int x, int y, string word) {
    int m = board.size();
    int n = board[0].size();
    int len = word.size();
    bool vis[m][n];
    memset(vis, 0, sizeof(vis));
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(x, y), 0));
    vis[x][y] = 1;
    while(!q.empty()) {
        pair<pair<int, int>, int> cur = q.front(); q.pop();
        if(cur.second == len-1 && board[cur.first.first][cur.first.second] == word[len-1]) { return true; }
        for (int i = 0; i < 4; i ++) {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];
            if(is_inside(nx, ny, m, n) && !vis[nx][ny] && cur.second+1 < len && board[nx][ny] == word[cur.second+1]){
                q.push(make_pair(make_pair(nx, ny), cur.second+1));
                vis[nx][ny] = 1;
            }
        }
    }
    return false;
}

bool exist(vector<vector<char> >& board, string word) {
    int m = board.size();
    if(m == 0 && word != "") return false;
    int n = board[0].size();
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if(board[i][j] == word[0]) {
                if(bfs(board, i, j, word)) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char> > board;
    vector<char> temp;
    temp.push_back('A');
    temp.push_back('B');
    temp.push_back('C');
    temp.push_back('E');
    board.push_back(temp);
    temp.clear();
    temp.push_back('S');
    temp.push_back('F');
    temp.push_back('C');
    temp.push_back('S');
    board.push_back(temp);
    temp.clear();
    temp.push_back('A');
    temp.push_back('D');
    temp.push_back('E');
    temp.push_back('E');
    board.push_back(temp);
    cout << exist(board, "ABCCED") << endl;
    cout << exist(board, "SFCS") << endl;
    cout << exist(board, "ABCB") << endl;
    return 0;
}
