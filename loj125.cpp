#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    int len = s.size();
    if(len == 0) return true;
    int i = 0;
    int j = len-1;
    while(i < j) {
        while(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) && i != j && i < len ) {
            i ++;
        }
        cout << i << endl;
        if((s[i] >= 'a' && s[i] <= 'z')){ s[i] = s[i]-'a'+'A'; }
        while(!((s[j] >= 'a' && s[i] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9')) && i != j && j >= 0) {
            j --;
        }
        cout << j << endl;
        if((s[j] >= 'a' && s[j] <= 'z')){ s[j] = s[j]-'a'+'A'; }
        if(s[i] != s[j]) { return false; }
        if(s[i] == s[j]) { i++; j --; }
    }
    return true;
}

int main() {
    cout << isPalindrome("ab2a") << endl;
    cout << isPalindrome("aaaaa") << endl;
    return 0;
}
