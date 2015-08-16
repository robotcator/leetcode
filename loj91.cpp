#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int numDecodings(string s) {
    int len = s.size();
    if(len == 0 || s[0] == '0') return 0;
    if(len == 1) return 1;
    int *dp = new int[len+1];
    //for(int i = 0; i <= len; i ++) dp[i] = 0;
    //memset(dp, 0, (len+1)*sizeof(int));
    //memset(dp, 0, sizeof(dp));

    dp[0] = 1; dp[1] = 1;
    for (int i = 1; i < len; i ++) {
        if(s[i] == '0') {
            if(s[i-1] == '1' || s[i-1] == '2') {
                dp[i+1] += dp[i-1];
            }else{
                return 0;
            }
        }else{
            dp[i+1] += dp[i];
            int temp = (s[i-1]-'0')*10 + (s[i]-'0');
            if(temp >= 11 && temp <= 26) {
                dp[i+1] += dp[i-1];
            }
        }
    }
    int ret = dp[len];
    delete[] dp;
    return ret;
}

int main() {
    cout << numDecodings("12") << endl;
    return 0;
}
