#include <string>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

string dict[] = {
    "abc", "def", "ghi",
    "jkl", "mno", "pqrs",
    "tuv", "wxyz"
};

void dfs(string digits, int depth, int maxDepth, string tmp, vector<string>& ans) {
    if(depth == maxDepth) {
        ans.push_back(tmp);
    }else{
        int index = digits[depth]-'2';
        for (int i = 0; i < (int)dict[index].size(); i ++) {
            dfs(digits, depth+1, maxDepth, tmp+dict[index][i], ans);
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.size() == 0) return ans;
    dfs(digits, 0, digits.size(), "", ans);
    return ans;
}

int main() {
    vector<string> ans = letterCombinations("23");

    vector<string>::iterator it;

    for (it = ans.begin(); it != ans.end(); it ++) {
        cout << *it << endl;
    }

    return 0;
}
