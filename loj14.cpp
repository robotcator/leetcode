#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    int size = strs[0].size();
    int i = 0;
    while(i < size) {
        bool flag = true;
        for (int j = 1; j < (int)strs.size(); j ++) {
            if(i > (int)strs[j].size()) {

            }
            if(strs[0][i] != strs[j][i]) {
                flag = false;
                break;
            }
        }
        if(!flag) return strs[0].substr(0, i);
        i ++;
    }
    return strs[0];
}

int main() {
    vector<string> v;
    v.push_back("a");
    v.push_back("b");

    cout << "begin test..." << endl;
    cout << longestCommonPrefix(v) << endl;
    cout << "end test..." << endl;
    return 0;
}
