#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(int n, int depth, vector<bool>& vis, vector<int>& pos,
        vector<vector<string> >& ans) {
    if(depth == n) {
        vector<string> tmp(n, string (n, '.'));
        for (int i = 0; i < n; i ++) {
            //cout << pos[i] << " ";
            tmp[i][pos[i]] = 'Q';
        }
        // cout << endl;
        ans.push_back(tmp);
    } else {
        for(int i = 0; i < n; i ++) {
            if(!vis[i]){
                bool flag = 1;
                for (int j = 0; j < depth; j ++) {
                    if(i-pos[j] == depth-j || i-pos[j] == j-depth) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    vis[i] = 1;
                    pos[depth] = i;
                    dfs(n, depth+1, vis, pos, ans);
                    vis[i] = 0;
                    pos[depth] = -1;
                }
            }
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<bool> vis(n+1, 0);
    vector<int> pos(n+1, -1);
    vector<vector<string> > ans;
    dfs(n, 0, vis, pos, ans);
    return ans;
}

int main() {
    vector<vector<string> > ans = solveNQueens(4);

    for (int i = 0; i < (int)ans.size(); i ++) {
        for (int j = 0; j < (int)ans[i].size(); j ++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
