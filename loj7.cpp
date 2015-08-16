#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string>

using namespace std;

int reverse(int x) {
    bool flag = false;
    long long xx = x;
    if (xx < 0) {
        flag = true;
        xx = -(long long)x;
    }
    string digit = "";
    while(xx) {
        digit += (xx%10 + '0');
        xx /= 10;
    }

    int len = digit.size();
    int i = 0;
    for (i = 0; i < len; i ++) {
        if(digit[i] != '0') break;
    }

    xx = 0;
    for (; i < len; i ++) {
            //cout << digit[i] << " " << xx << " " << (long long)xx*10 + digit[i]-'0' << endl;
        if(xx*10 + digit[i]-'0' > (1<<31)-1) {
            xx = 0;
            break;
        }else{
            xx = xx*10 + digit[i]-'0';
        }
    }
    if(flag) xx = xx*-1;
    return xx;
}

int main() {
    cout << 2147483647 << endl;
    cout << (1<<31) -1 << endl;
    cout << INT_MAX << endl;
    printf("%d\n", reverse(-2147483648));
    printf("%d\n", reverse(1534236469));
    printf("%d\n", reverse(1534236469));
    return 0;
    printf("%d\n", reverse(-100));
    printf("%d\n", reverse(100));
    printf("%d\n", reverse(1000000003));
    return 0;
}
