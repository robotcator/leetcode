#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// naive algorithm
vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    int len = nums.size();
    if(len < 3) return result;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < len; i ++) {
        int st = i+1, ed = len-1;
        while(st < ed) {
            int sum = nums[i] + nums[st] + nums[ed];
            vector<int> item;
            if(sum == 0) {
                item.push_back(nums[i]);
                item.push_back(nums[st]);
                item.push_back(nums[ed]);
                result.push_back(item);
                st ++; ed --;
                while(st < ed && nums[st-1] == nums[st]) st++;
                while(st < ed && nums[ed+1] == nums[ed]) ed --;
            }else if(sum < 0) {
                st ++;
                while(st < ed && nums[st-1] == nums[st]) st++;
            }else {
                ed --;
                while(st < ed && nums[ed+1] == nums[ed]) ed --;
            }
        }
        while(i+1 < len && nums[i] == nums[i+1]) i ++;
    }
    return result;
}

int main() {
    vector<int> v;
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-1);
    v.push_back(-4);

    vector<vector<int> > ans = threeSum(v);

    for (int i = 0; i < (int)ans.size(); i ++) {
        for (int j = 0; j < (int)ans[i].size(); j ++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

