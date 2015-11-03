#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
    int n = s.size();
    int maxlen = 0;
    int *dp = new int[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
        if(s[i-1] == '(') dp[i] = 0;
        else {
            int j = i-2-dp[i-1];
            if(j >= 0 && s[j] == '(') {
                dp[i] = 2+dp[i-1]+dp[j];
                maxlen = max(maxlen, dp[i]);
            }else{
                dp[i] = 0;
            }
        }
    }
    return maxlen;
}

int main() {
    cout << longestValidParentheses("(())") << endl;
    return 0;
}
