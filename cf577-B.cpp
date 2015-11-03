#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e6+10;
int a[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        a[i] %= m;
    }
    if(n >= m) printf("YES\n");
    else{
        vector<int> p(m, 0), np(m, 0);
        for (int i = 0; i < n; i ++) {
            int v = a[i];
            np[v] = 1;
            for (int i = 0; i < m; i ++) {
                if(p[i] != 0) {
                    np[i] = 1;
                    np[(v+i)%m] = 1;
                }
            }
            for (int i = 0; i < m; i ++) cout << np[i] << " ";
            cout << endl;
            copy(np.begin(), np.end(), p.begin());
        }
        if(p[0]) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }
    return 0;
}
