#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& num) {
    int len = num.size();
    int pos = len-1;
    while(pos > 0 && num[pos] <= num[pos-1]) pos --;
    cout << pos << endl;
    if(pos == 0) {
        // reverse
        reverse(num.begin(), num.end());
        return ;
    }
    int npos = pos;

    for (int i = len-1; i >= pos; i --) {
        if(num[i] > num[pos-1]) {
            npos = i;
            break;
        }
    }
    swap(num[pos-1], num[npos]);
    reverse(num.begin()+pos, num.end());
}

int main() {
    vector<int> v;
    /*
    v.push_back(5);
    v.push_back(6);
    v.push_back(8);
    v.push_back(7);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
*/
    v.push_back(5);
    v.push_back(1);
    v.push_back(1);
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << " ";
    }
    cout << endl;

    nextPermutation(v);

    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << " ";
    }
    return 0;
}
