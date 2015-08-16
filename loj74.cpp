#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int l, r;
    int m = matrix.size();
    int n = matrix[0].size();
    l = 0; r = m*n;
    while (l < r) {
        int mid = (l+r)/2; int mid_x = mid / n; int mid_y = mid % n;
        if(matrix[mid_x][mid_y] == target) return true;
        else if(matrix[mid_x][mid_y] > target) r = mid;
        else l = mid+1;
    }
    return false;
}

int main() {
    int array[10][10] = {
                      {1,   3,  5,  7},
                      {10, 11, 16, 20},
                      {23, 30, 34, 50}
                    };
    vector<vector<int> > q;
    for (int i = 0; i < 3; i ++) {
        vector<int> p;
        for (int j = 0; j < 4; j ++) {
            p.push_back(array[i][j]);
        }
        q.push_back(p);
    }
    cout << searchMatrix(q, 1) << endl;
    cout << searchMatrix(q, 2) << endl;
    return 0;
}
