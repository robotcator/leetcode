#include <iostream>

using namespace std;

int mySqrt(int x) {
    if(x <= 0) return 0;
    int l, r;
    l = 1; r = x;
    while(l < r) {
        int mid = (l+r)/2;
        if(x / mid == mid) return mid;
        else if(x / mid > mid) {
            if(x / (mid+1) < mid+1) return mid;
            else l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    for (int i = 1; i < 10; i ++)
        cout << mySqrt(i) << endl;
    return 0;
}
