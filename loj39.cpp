#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(vector<int> candidates, int target,
        vector<int> rec,
        set<vector<int> > &ans) {
    if(target == 0) {
        vector<int> tmp;
        for (int i = 0; i < (int)rec.size(); i ++) {
            cout << rec[i] << " ";
            tmp.push_back(rec[i]);
        }
        cout << endl;
        sort(tmp.begin(), tmp.end());
        ans.insert(tmp);
        return ;
    }else{
        int len = candidates.size();
        for (int i = 0; i < len; i ++) {
            if(target-candidates[i] < 0) return ;
            else {
                rec.push_back(candidates[i]);
                dfs(candidates, target-candidates[i],
                        rec, ans);
                rec.pop_back();
            }
        }
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<int> rec;
    vector<vector<int> > tmp;
    set<vector<int> > ans;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, rec, ans);

    set<vector<int> >:: iterator it;
    for (it = ans.begin(); it != ans.end(); it ++) {
        tmp.push_back(*it);
    }
    return tmp;
}

int main() {
    vector<int> ans;
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(6);
    ans.push_back(8);

    vector<vector<int> > tmp = combinationSum(ans, 7);

    for (int i = 0; i < (int)tmp.size(); i ++) {
        for (int j = 0; j < (int)tmp[i].size(); j ++) {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

