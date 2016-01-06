#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool dfs(vector<int> *G, vector<int>& vis, int u,
        vector<int> &ans) {
    vis[u] = 1;
    for (int i = 0; i < (int)G[u].size(); i ++) {
        int v = G[u][i];
        if(vis[v] == 0) {
            vis[v] = 1;
            if(!dfs(G, vis, v, ans)) {
                return false;
            }
        }else if(vis[v] == 1){
            return false;
        }
    }
    vis[u] = 2;
    ans.push_back(u);
    return true;
}


vector<int> findOrder(int numCourses,
        vector<pair<int, int> >& prerequisites) {
    vector<int> G[numCourses];
    vector<int> vis(numCourses, 0);
    vector<int> ans;
    for (int i = 0; i < (int)prerequisites.size(); i ++) {
        pair<int, int> edge = prerequisites[i];
        G[edge.second].push_back(edge.first);
    }

    for (int i = 0; i < numCourses; i ++) {
        if(vis[i] == 0) {
          if(!dfs(G, vis, i, ans)){
            ans.clear();
            return ans;
          }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<pair<int, int> > p;
    p.push_back(make_pair(1, 0));
    p.push_back(make_pair(2, 0));
    p.push_back(make_pair(3, 1));
    p.push_back(make_pair(3, 2));

    vector<int> v;

    v = findOrder(4, p);
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << " ";
    }
    cout << endl;

    p.clear();
    v = findOrder(1, p);
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << " ";
    }
    cout << endl;

    p.clear();
    p.push_back(make_pair(0, 1));
    p.push_back(make_pair(2, 0));
    p.push_back(make_pair(1, 3));
    p.push_back(make_pair(3, 2));
    v = findOrder(4, p);
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << " ";
    }
    cout << endl;



    return 0;
}
