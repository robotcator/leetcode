#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void dfs(int left, int right, string s, vector<string>& v) {
    if(left == 0 && right == 0) {
        v.push_back(s);
    }else{
        if(left > 0) {
            dfs(left-1, right, s+"(", v);
        }
        if(right > 0 && left < right) {
            dfs(left, right-1, s+")", v);
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> v;
    dfs(n, n, "", v);
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << endl;
    }
    return v;
}

int main() {
    generateParenthesis(1);
    generateParenthesis(2);
    generateParenthesis(3);
    generateParenthesis(4);

    return 0;
}
