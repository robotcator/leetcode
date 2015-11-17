#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(int n, int depth, vector<bool>& vis, vector<int>& pos,
        int& ans) {
    if(depth == n) {
        ans ++;
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

int totalNQueens(int n) {
    vector<bool> vis(n+1, 0);
    vector<int> pos(n+1, -1);
    int ans = 0;
    dfs(n, 0, vis, pos, ans);
    return ans;
}

int main() {

    cout << totalNQueens(4) << endl;

    return 0;
}
