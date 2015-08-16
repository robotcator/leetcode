#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();
    int n = triangle[m-1].size();
    int **dp = new int*[2];
    for (int i = 0; i < 2; i ++) {
        dp[i] = new int[n];
        memset(dp[i], 0, n*sizeof(int));
    }
    dp[0][0] = triangle[0][0];
    int flag = 1;
    for (int i = 1; i < m; i ++) {
        for (int j = 0; j < triangle[i].size(); j ++) {
              if(j == 0) dp[flag][j] = dp[flag^1][j] + triangle[i][j];
              else if(j == triangle[i].size()-1) dp[flag][j] = dp[flag^1][j-1] + triangle[i][j];
              else dp[flag][j] = min(dp[flag^1][j], dp[flag^1][j-1]) + triangle[i][j];
        }
        flag ^= 1;
    }
    int ret = 0x3f3f3f3f;
    for(int i = 0; i < n; i ++) {
        if(dp[flag^1][i] < ret) ret = dp[flag^1][i];
    }
    return ret;
}

int main() {
    vector<vector<int> > v;
    vector<int> vv;
    vv.push_back(2);
    v.push_back(vv);
    cout << minimumTotal(v) << endl;
    v.clear();
    vv.clear();
   // [[-1],[2,3],[1,-1,-3]]
    vv.push_back(-1);
    v.push_back(vv);
    vv.clear();
    vv.push_back(2);
    vv.push_back(3);
    v.push_back(vv);
    vv.clear();
    vv.push_back(1);
    vv.push_back(-1);
    vv.push_back(-3);
    v.push_back(vv);
     cout << minimumTotal(v) << endl;
    return 0;
}
