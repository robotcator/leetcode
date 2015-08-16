#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <hash_set>
#include <map>
#include <unordered_set>

using namespace std;

class Solution{
public:
     vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> ust;

        vector<string> vs;
        map<int, int> mp;
        mp.clear();
        vs.clear();
        int len = s.size();
        for (int i = 0; i <= len-10; i ++) {
            string sub = s.substr(i, 10);
            int hash = hash_fun(sub);
            if (mp.find(hash) != mp.end()) {
                mp[hash] += 1;
                if (mp[hash] == 2) vs.push_back(sub);
            } else {
                mp[hash] = 1;
            }
        }
        return vs;
    }
    int hash_fun(string s) {
        int len = s.size();
        int digit, ans;
        digit = ans = 0;
        for (int i = len-1; i >= 0; i --) {
            if (s[i] == 'A') {
                digit = 0;
            } else if (s[i] == 'C') {
                digit = 1;
            } else if (s[i] == 'G') {
                digit = 2;
            } else if (s[i] == 'T') {
                digit = 3;
            }
            ans = ans * 4 + digit;
        }
        return ans;
    }
    /*
    // mle
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vs;
        vs.clear();
        int len = s.size();
        int *vis = new int[1100000];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < len-10; i ++) {
            string sub = s.substr(i, 10);
            int hash = hash_fun(sub);
           // cout << hash << endl;
            if (vis[hash] == 0) {
                vis[hash] = 1;
            }else if (vis[hash] == 1) {
                vs.push_back(sub);
                vis[hash] = 2;
            }
        }
        delete vis;
        return vs;
    }
    int hash_fun(string s) {
        int len = s.size();
        int digit, ans;
        digit = ans = 0;
        for (int i = len-1; i >= 0; i --) {
            if (s[i] == 'A') {
                digit = 0;
            } else if (s[i] == 'C') {
                digit = 1;
            } else if (s[i] == 'G') {
                digit = 2;
            } else if (s[i] == 'T') {
                digit = 3;
            }
            ans = ans * 4 + digit;
        }
        return ans;
    }
    */
    /*
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        map<string, int>::iterator it;
        mp.clear();
        int len = s.size();
        for (int i = 0; i < len-10; i ++) {
            string sub = s.substr(i, 10);
            if (mp.find(sub) != mp.end()) {
                mp[sub] += 1;
            } else {
                mp[sub] = 1;
            }
        }
        vector<string> vs;
        vs.clear();
        for (it = mp.begin(); it != mp.end(); it ++) {
            if (it->second >= 2) {
                vs.push_back(it->first);
            }
        }
        return vs;
    }
    */
};

int main() {
    Solution *solu = new Solution();
   // string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string s = "AAAAAAAAAAA";
    vector<string> ans = solu->findRepeatedDnaSequences(s);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    return 0;
}
