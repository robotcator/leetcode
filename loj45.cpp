#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

/*
 * dfs solution tle
void dfs(int index, int total, vector<int>&num, int step, int &ans){
    printf("%d\n", index);
    if(num[index] == 0 || index > total) {
        return ;
    }
    if(index == total){
        if(step < ans){
            ans = step;
            return ;
        }
    }
    for (int i = 1; i <= num[index]; i ++){
        dfs(index+i, total, num, step+1, ans);
    }
}

int jump(vector<int>& num){
    int ans = num.size();
    dfs(0, num.size()-1, num, 0, ans);
    return ans;
}

*/

/*
 *o(n^2) tle
int jump(vector<int>& num){
    int size = num.size();
    if(size == 0) return 0x3f3f3f3f;
    int *dp = new int[size];
    dp[0] = 0;
    for (int i = 1; i < size; i ++) dp[i] = size;
    for (int i = 1; i < size; i ++) {
        for (int j = 0; j < i; j ++) {
            if(num[j] + j >= i && dp[j]+1 < dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
    }
    int ans = dp[size-1];
    delete dp;
    return ans;
}
*/

//
int jump(vector<int>& num) {
    int size = num.size();
    if(size == 1) return 0;
    int st = 0, ed = num[0];
    int cnt = 1, max = 0;
    while(ed < size-1) {
        int index = st;
        while(index <= ed) {
            max = max > index+num[index] ? max : index+num[index];
            index ++;
        }
        st = index;
        ed = max;
        cnt ++;
    }
    return cnt;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(4);

    cout << jump(v) << endl;

    return 0;
}
