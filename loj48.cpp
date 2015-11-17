#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> >& matrix) {
    int m = matrix.size();
    if(m == 0) return;
    int n = matrix[0].size();
    for (int i = 0; i < m; i ++) {
        for (int j = i; j < n; j ++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
        for (int j = 0; j < n/2; j ++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n-1-j];
            matrix[i][n-1-j] = tmp;
        }
    }
}

int main() {
    vector<vector<int> > matrix;
    vector<int> tmp;
    int n = 3;
    for (int i = 0; i < n; i ++) {
        tmp.clear();
        for (int j = 0; j < n; j ++) {
            tmp.push_back(i*3+j+1);
        }
        matrix.push_back(tmp);
    }

    rotate(matrix);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
