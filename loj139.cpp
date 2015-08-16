#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int len = s.size();
    bool *vis = new bool[len+1];
    for (int i = 0; i < len+1; i ++) vis[i] = false;
    vis[0] = true;
    for (int i = 1; i <= len; i ++) {
        for (int j = i-1; j >= 0; j --) {
                cout << s.substr(j, i) << endl;
            if(vis[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                vis[i] = true;
                break;
            }
        }
    }
    bool res = vis[len];
    delete[] vis;
    return res;
}

int main() {
    unordered_set<string> word;
    word.insert("leet");
    word.insert("code");
    cout << wordBreak("leetcode", word) << endl;
    word.clear();
    word.insert("a");
    cout << wordBreak("a", word) << endl;
    word.clear();
    //word.insert("applepie");
    word.insert("pear");
    word.insert("apple");
    word.insert("peach");
    cout << wordBreak("applepie", word) << endl;
    return 0;
}
