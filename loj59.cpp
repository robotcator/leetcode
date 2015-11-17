#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

void test(vector<vector<int> > ans) {
    for (int i = 0; i < (int)ans.size(); i ++) {
        for (int j = 0; j < (int)ans[i].size(); j ++) {
            cout << ans[i][j] <<  " ";
        }
        cout << endl;
    }
}

// attention for the x1 = x2 = y1 = y1 situation
void dfs(int x1, int y1, int x2, int y2, int start,
        vector<vector<int> > &ans) {
    if(x1 <= x2 && y1 <= y2) {
        cout << x1 << x2 << y1 << y2 << endl;
        int i, j;
        i = y1;
        while(i < y2) {
            ans[x1][i] = start ++;
            i ++;
        }
        j = x1;
        while(j < x2) {
            ans[j][y2] = start ++;
            j ++;
        }

        while(i > y1) {
            ans[x2][i] = start ++;
            i --;
        }

        while(j > x1) {
            ans[j][y1] = start ++;
            j --;
        }

        if(x1 == x2 && x2 == y1 && y1 == y2) ans[x1][y1] = start ++;

        test (ans);

        dfs(x1+1, y1+1, x2-1, y2-1, start, ans);

    }
}

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ans(n, vector<int> (n, 1));
    dfs(0, 0, n-1, n-1, 1, ans);
    return ans;
}

int main() {
    generateMatrix(3);
    generateMatrix(5);
    generateMatrix(6);
    generateMatrix(7);
    return 0;
}
