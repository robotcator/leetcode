#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int x, int y, int m, int n,
        vector<vector<int> > matrix,
        vector<int>& v) {

    cout << x << " " << y << " " << m << " " << n << endl;

    if(x <= m && y <= n) {

        if(x == m && y == n) {
            v.push_back(matrix[x][y]);
            return ;
        }

        for (int i = y; i <= n; i ++) {
            cout << matrix[x][i] << endl;
            v.push_back(matrix[x][i]);
        }
        cout << endl;

        for (int i = x+1; i <= m; i ++) {
            cout << matrix[i][n] << endl;
            v.push_back(matrix[i][n]);
        }
        cout << endl;
        if(x < m) {
            for (int i = n-1; i >= y; i --) {
                cout << matrix[m][i] << endl;
                v.push_back(matrix[m][i]);
            }
        }
        cout << endl;
        if(y < n) {
            for (int i = m-1; i >= x+1; i --) {
                cout << matrix[i][y] << endl;
                v.push_back(matrix[i][y]);
            }
        }
        cout << x+1 << y+1 << m-1 << n-1 << endl;

        for (int i = 0; i < (int)v.size(); i ++) cout << v[i] << " ";
        cout << endl;
        dfs(x+1, y+1, m-1, n-1, matrix, v);
    }
}

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> v;
    if(matrix.size() == 0) return v;
    if(matrix.size() == 1) return matrix[0];
    int m = matrix.size();
    int n = matrix[0].size();
    dfs(0, 0, m-1, n-1, matrix, v);
    return v;
}

int main() {
    vector<vector<int> > matrix;
    vector<int> tmp;

    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i ++) {
        tmp.clear();
        for (int j = 0; j < n; j ++) {
            tmp.push_back(i*n+j);
            cout << i*n+j << " ";
        }
        cout << endl;
        matrix.push_back(tmp);
    }

    vector<int> ans = spiralOrder(matrix);

    for (int i = 0; i < (int)ans.size(); i ++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
