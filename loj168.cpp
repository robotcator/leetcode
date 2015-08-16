#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n) {
            if (n % 26 == 0){
                ans = ans + 'Z';
                n = n - 1;
            }else {
                ans = ans + char(n % 26 - 1 + 'A');
            }
            n /= 26;
        }
        int len = ans.size();
        for (int i = 0; i < len/2; i ++) {
            int temp = ans[i];
            ans[i] = ans[len-i-1];
            ans[len-i-1] = temp;
        }
        return ans;
    }
};

int main() {
    Solution *solu = new Solution();
    cout << solu->convertToTitle(26) << endl;
    cout << solu->convertToTitle(52) << endl;
    cout << solu->convertToTitle(27) << endl;
    cout << solu->convertToTitle(28) << endl;
    return 0;
}
