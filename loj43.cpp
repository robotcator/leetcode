#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return "0";
    int len1 = num1.size();
    int len2 = num2.size();
    string ans = "";
    for (int i = len1-1; i >= 0; i --) {
        int mul = num1[i]-'0';
        int carry = 0;
        string tmp(len1-1-i, '0');
        for (int j = len2-1; j >= 0; j --) {
            int x = mul * (num2[j]-'0') + carry;
            tmp += x%10 + '0';
            carry = x/10;
        } // mul
        if(carry) tmp += (carry+'0');
        reverse(ans.begin(), ans.end());
        int add1 = ans.size();
        int add2 = tmp.size();
        int p1 , p2, x, y;
        carry = p1 = p2 = 0;
        string sum = "";
        while(p1 < add1 || p2 < add2) {
            if(p1 < add1) x = ans[p1]-'0';
            else x = 0;
            if(p2 < add2) y = tmp[p2]-'0';
            else y = 0;
            int z = x + y + carry;
            sum += (z%10) + '0';
            carry = z/10;
            p1 ++;
            p2 ++;
        }
        if(carry) sum += (carry+'0');
        reverse(sum.begin(), sum.end());
        ans = sum;
    }
    return ans;
}

int main() {
    cout << multiply("1234", "6789") << endl;
    cout << multiply("1234", "0") << endl;
    cout << multiply("1234", "1") << endl;
    return 0;
}
