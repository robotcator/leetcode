#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(vector<int> candidates, int target,
        vector<int> rec,
        set<vector<int> > &ans, vector<int> &vis) {
    if(target == 0) {
        vector<int> tmp;
        for (int i = 0; i < (int)rec.size(); i ++) {
            //cout << rec[i] << " ";
            tmp.push_back(rec[i]);
        }
        //cout << endl;
        sort(tmp.begin(), tmp.end());
        ans.insert(tmp);
        return ;
    }else{
        int len = candidates.size();
        for (int i = 0; i < len; i ++) {
            if(!vis[i]) {
                if(target-candidates[i] < 0) return ;
                rec.push_back(candidates[i]);
                vis[i] = 1;
                dfs(candidates, target-candidates[i],
                        rec, ans, vis);
                rec.pop_back();
                vis[i] = 0;
            }
        }
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector<int> rec;
    vector<vector<int> > tmp;
    vector<int> vis(candidates.size(), 0);
    set<vector<int> > ans;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, rec, ans, vis);

    set<vector<int> >:: iterator it;
    for (it = ans.begin(); it != ans.end(); it ++) {
        tmp.push_back(*it);
    }
    return tmp;
}

int main() {

    int a[10] = {0, 0, 0, 1, 1};

    do{
        for (int i = 0; i < 5; i ++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }while(next_permutation(a, a+5));

    /*
    vector<int> ans;
    ans.push_back(10);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(7);
    ans.push_back(6);
    ans.push_back(1);
    ans.push_back(5);

    vector<vector<int> > tmp = combinationSum(ans, 8);

    for (int i = 0; i < (int)tmp.size(); i ++) {
        for (int j = 0; j < (int)tmp[i].size(); j ++) {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }
    */
    vector<int> ans;
    ans.push_back(3);
    ans.push_back(1);
    ans.push_back(3);
    ans.push_back(5);
    ans.push_back(1);
    ans.push_back(5);
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(2);
    ans.push_back(5);
    ans.push_back(4);

    vector<vector<int> > tmp = combinationSum2(ans, 1);

    for (int i = 0; i < (int)tmp.size(); i ++) {
        for (int j = 0; j < (int)tmp[i].size(); j ++) {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

