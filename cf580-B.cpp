#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5+10;

struct Friend {
    int m;
    long long s;
};

Friend F[maxn];

struct _myClassLess{
    bool operator() (const Friend& left, const Friend& rigth) {
        return left.m < rigth.m;
    }

    bool operator() (const Friend& left, int key) {
        return left.m < key;
    }

    bool operator() (int key, const Friend& right) {
        return key < right.m;
    }
}myClassLess;

bool cmp(const Friend& left, const Friend& right) {
    return left.m < right.m;
}


int main() {
    int n, d;
    while(scanf("%d %d", &n, &d) != EOF) {
        F[0].m = F[0].s = 0;
        for (int i = 1; i <= n; i ++) {
            //scanf("%d %lld", &F[i].m, &F[i].s);
            cin >> F[i].m >> F[i].s;
        }
        sort(F+1, F+n+1, myClassLess);
        for (int i = 1; i <= n; i ++) {
            cout << F[i].m << " " << F[i].s  << endl;
            F[i].s = F[i].s + F[i-1].s;
        }

        long long maxAns = 0;

        for (int i = 1; i <= n; i ++) {
            int target = F[i].m + d;

            cout << target << endl;

            int up = lower_bound(F+i, F+n+1, target, myClassLess)-F;

            if(F[up].m >= target) up --;

            if(up > n) up = n;
            cout << up << endl;

            long long sum = F[up].s - F[i-1].s;
            if(sum > maxAns) maxAns = sum;
        }

        cout << maxAns << endl;
    }
    return 0;
}
