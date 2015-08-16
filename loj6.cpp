#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string convert(string s, int numRows) {
        vector<string> newString;
        int len = s.size();
        int i, j;
        i = j = 0;
        for (int i = 0; i < numRows; i ++) newString.push_back("");
        while(i < len) {
            while(j < numRows && i < len) {
               // cout << j << " " << i << endl;
                newString[j++] += s[i++];
            }
            j -= 2;
            if(j < 0) j = 0;
            while(j > 0 && i < len) {
               // cout << j << " " << i << endl;
                newString[j--] += s[i++];
            }
           // cout << i << endl;
           // cout << j << endl;
        }
        string ans = "";
        for (int i = 0; i < numRows; i ++) ans += newString[i];
        return ans;
}

int main() {
    cout << convert("AB", 1) << endl;
    cout << convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
