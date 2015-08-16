#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool dfs(int u, vector<int> *G, int* &vis) {
    vis[u] = -1;
    for(int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        if(vis[v] == -1) { return false; }
        else if(!vis[v]){ if(!dfs(v, G, vis)) return false; }
    }
    vis[u] = 1;
    return true;
}

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<int> G[numCourses];
    int size = prerequisites.size();
    for (int i = 0; i < size; i ++) {
        G[prerequisites[i].first].push_back(prerequisites[i].second);
    }
    int *vis = new int[numCourses];
    memset(vis, 0, numCourses*sizeof(int));
    for(int i = 0; i < numCourses; i ++) {
        if(!vis[i]) {
            if(!dfs(i, G, vis)) return false;
        }
    }
    return true;
}


int main(){
    vector<pair<int, int> > prerequisites;
    int n, x, y;
    freopen("loj207.txt", "r", stdin);
    scanf("%d, [", &n);
    for(int i = 0; i < n; i ++) {
        scanf("[%d,%d],", &x, &y);
        //cout << x << " " << y << endl;
        prerequisites.push_back(make_pair(x, y));
    }
    cout << prerequisites.size() << endl;
    cout << canFinish(n, prerequisites) << endl;

    prerequisites.clear();

    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(0, 1));

    cout << prerequisites.size() << endl;
    cout << canFinish(n, prerequisites) << endl;


    return 0;
}


