#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string getPermutation(int n, int k) {
    vector<int> v(n, 1);
    for (int i = 0; i < n; i ++) v[i] = i+1;
    int cnt = 0;
    do {
        cnt ++;
        if(n == k) break;
    }while(next_permutation(v.begin(), v.end()));
    string ans = "";
    for (int i = 0; i < n; i ++) ans += (v[i]+'0');
    return ans;
}

int main() {
    cout << getPermutation(9, 136371) << endl;
    return 0;
}
