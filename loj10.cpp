#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
   int m = s.size();
   int n = p.size();
   bool **dp = new bool*[m+1];
   for (int i = 0; i <= m; i ++) {
       dp[i] = new bool[n+1];
       //for (int j = 0; j <= n; j ++) {
       // printf("%d ", dp[i][j]);
       //}
       //printf("\n");
   }
   dp[0][0] = 1;
   for (int i = 0; i < m; i ++) {
       for (int j = 0; j < n; j ++) {
            if (s[i] == p[j]) dp[i+1][j+1] = dp[i][j];
            else if(p[j] == '.') dp[i+1][j+1] = dp[i][j];
            else if(p[j] == '*') {
                if(s[i] == p[j-1]) dp[i+1][j+1] = dp[i][j];
            }
       }
   }

}

int main() {
    isMatch("aa","a");
    isMatch("aa","aa");
    isMatch("aaa","aa");
    isMatch("aa", "a*");
    isMatch("aa", ".*");
    isMatch("ab", ".*");
    isMatch("aab", "c*a*b");
    return 0;
}
