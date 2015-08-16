#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<int> G[numCourses];
    int size = prerequisites.size();
    int in[numCourses];

    memset(in, 0, sizeof(in));

    for (int i = 0; i < size; i ++) {
        G[prerequisites[i].first].push_back(prerequisites[i].second);
        in[prerequisites[i].second] ++;
    }
    queue<int> q;

    for (int i = 0; i < numCourses; i ++) {
        if(!in[i]) { q.push(i); }
    }

    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop(); cnt ++;
        for (int i = 0; i < G[cur].size(); i ++) {
            int next = G[cur][i];
            in[next] --;
            if(!in[next]) { q.push(next); }
        }
    }
    if(cnt != numCourses) return false;
    else return true;
}


int main(){
    vector<pair<int, int> > prerequisites;
    int n, x, y;
    freopen("loj207in.txt", "r", stdin);
    scanf("%d, [", &n);
    for(int i = 0; i < n; i ++) {
        scanf("[%d,%d],", &x, &y);
        //cout << x << " " << y << endl;
        prerequisites.push_back(make_pair(0, 1));
    }
    cout << prerequisites.size() << endl;
    cout << canFinish(n, prerequisites) << endl;
    return 0;
}


