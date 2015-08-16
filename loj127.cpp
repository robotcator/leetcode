#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    queue<pair<string, int> > q;
    unordered_map<string, bool> mp;
    q.push(make_pair(beginWord, 1));
    wordDict.insert(endWord);
    mp[beginWord] = true;
    while(!q.empty()) {
        pair<string, int> cur = q.front(); q.pop();
        string curString = cur.first;
        if(curString == endWord) return cur.second;
        int len = curString.size();
        for (int i = 0; i < len; i ++) {
            for (char ch = 'a'; ch <= 'z'; ch ++) {
                if(ch == curString[i]) continue;
                string temp = curString;
                temp[i] = ch;
                if(wordDict.find(temp) != wordDict.end() && !mp[temp]) {
                    q.push(make_pair(temp, cur.second+1));
                    mp[temp] = true;
                }
            }
        }
    }
    return 0;
}

int main() {
    unordered_set<string> wordDict;
    wordDict.insert("hot");
    wordDict.insert("dot");
    wordDict.insert("dog");
    wordDict.insert("lot");
    wordDict.insert("log");
    cout << ladderLength("hit", "cog", wordDict) << endl;
    return 0;
}
