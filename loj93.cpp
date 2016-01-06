#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string s, int p) {
    if(p == 0) {
        if(s.size() >= 2) return false;
        else return true;
    }else{
        if(s[0] == '0') return false;
        else return true;
    }
}

void dfs(int depth, int n, string s,
        vector<int> pos, vector<string>& ans) {
    if(depth == n) {
        string sp1 = s.substr(0, pos[0]-0);
        cout << sp1 << endl;
        int p1 = stoi(sp1);
        if(!check(sp1, p1) || p1 < 0 || p1 > 255) return;
        string sp2 = s.substr(pos[0], pos[1]-pos[0]);
        cout << sp2 << endl;
        int p2 = stoi(sp2);
        if(!check(sp2, p2) || p2 < 0 || p2 > 255) return;
        string sp3 = s.substr(pos[1], pos[2]-pos[1]);
        cout << sp3 << endl;
        int p3 = stoi(sp3);
        if(!check(sp3, p3) || p3 < 0 || p3 > 255) return;
        string sp4 = s.substr(pos[2], s.size()-pos[2]);
        cout << sp4 << endl;
        int p4 = stoi(sp4);
        if(!check(sp4, p4) || p4 < 0 || p4 > 255) return;
        ans.push_back(sp1+"."+sp2+"."+sp3+"."+sp4);
        cout << ans[ans.size()-1] << endl;
    }else{
        int len = s.size();
        for (int i = depth == 0 ? 1 : pos[depth-1]+1; i < len; i ++) {
            pos[depth] = i;
            if(len-pos[depth] > (3-depth)*3) continue;
            dfs(depth+1, n, s, pos, ans);
        }
    }
}

// stoi may out of range
// not prefix 0
// the input may out of range
vector<string> restoreIpAddresses(string s) {
    int len = s.size();
    vector<string> ans;
    if(len > 12) return ans;
    vector<int> pos(3, 0);
    dfs(0, 3, s, pos, ans);
    return ans;
}

int main() {
    restoreIpAddresses("010010");
    restoreIpAddresses("2736786374048");

    restoreIpAddresses("1231231231234");
    restoreIpAddresses("25525511135");
    return 0;
}
