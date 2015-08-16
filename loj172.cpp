#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int get_five_multi(int n) {
    int cnt = 0;
    int flag = 1;
    long long x = 5;
    while (n - x >= 0) {
        cnt = cnt + flag * (n / x);
        //flag *= -1;
        x *= 5;
    }
    return cnt;
}

int get_two_multi(int n) {
    int cnt = 0;
    int flag = 1;
    int x = 2;
    while (x <= n) {
        cnt = cnt + flag * (n / x);
        //flag *= -1;
        x *= 2;
    }
    return cnt;
}

int trailingZeroes(int n) {
   // int two = get_two_multi(n);
    int five = get_five_multi(n);
  return five;
//    int num = floor(log(n)/log(5));
//cout << num << " d"<< endl;
//    return (num+1)*(num)/2;
}

class Solution {
public:
        int get_five_multi(int n) {
        int cnt = 0;
        int flag = 1;
        int x = 5;
        while (x <= n) {
            cnt = cnt + flag * (n / x);
            //flag *= -1;
            x *= 5;
        }
        return cnt;
    }

    int get_two_multi(int n) {
        int cnt = 0;
        int flag = 1;
        int x = 2;
        while (x <= n) {
            cnt = cnt + flag * (n / x);
            //flag *= -1;
            x *= 2;
        }
        return cnt;
    }

    int trailingZeroes(int n) {
        //int two = get_two_multi(n);
        int five = get_five_multi(n);
        return five;
        //int num = floor(log(n)/log(5));

        //return (num+1)*(n)/2;
    }
};

int main() {
    cout << log2(2147483647) << endl;
    cout << trailingZeroes(2147483647) << endl;
    Solution* ans = new Solution();
    cout << ans->trailingZeroes(2147483647) << endl;
    cout << trailingZeroes(1808548329) << endl;
    cout << trailingZeroes(6) << endl;
    cout << trailingZeroes(10) << endl;


    cout << get_two_multi(2) << endl;
    cout << get_two_multi(4) << endl;
    cout << get_two_multi(6) << endl;
    cout << get_two_multi(8) << endl;
    cout << get_two_multi(10) << endl;
    cout << get_two_multi(16) << endl;
    return 0;
}
