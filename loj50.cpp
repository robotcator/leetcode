#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

double myPow(double x, int n) {
    if(n == 0) return 1;
    int flag = n > 0 ? 1 : -1;
    long long nn = (long long)n;
    nn = nn > 0 ? nn : -nn;
    double ans = 1;
    double p = x;
    while (nn) {
        if(nn & 1) {
            ans *= p;
        }
        p = p * p;
        nn >>= 1;
    }
    if(flag == 1) return ans;
    else return 1.0/ans;
}

int main() {
    cout << fabs(-2147483648) << endl;
    cout << myPow(1.00000, -2147483648) << endl;
    cout << myPow(2, 3) << endl;
    cout << myPow(2, -2) << endl;
    return 0;
}
