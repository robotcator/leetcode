#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    int len = nums.size();
    vector<vector<int> > result;
    if(len < 4) return result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < len; i ++) {
        for (int j = i+1; j < len; j ++) {
            int st = j+1;
            int ed = len-1;
            while(st < ed) {
                int sum = nums[i]+nums[j]+nums[st]+nums[ed];
                if(sum == target) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[st]);
                    tmp.push_back(nums[ed]);
                    result.push_back(tmp);
                    st ++; ed--;

                    while(st < ed && nums[st-1] == nums[st]) st ++;
                    while(st < ed && nums[ed+1] == nums[ed]) ed --;
                }else if(sum < target) {
                    st ++;
                    while(st < ed && nums[st-1] == nums[st]) st ++;
                }else{
                    ed --;
                    while(st < ed && nums[ed+1] == nums[ed]) ed --;
                }
            }
            while(j+1 < len && nums[j] == nums[j+1]) j ++;
        }
        while(i+1 < len && nums[i] == nums[i+1]) i ++;
    }
    return result;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(-1);
    v.push_back(0);
    v.push_back(-2);
    v.push_back(2);

    vector<vector<int> > ans = fourSum(v, 0);

    for (int i = 0; i < ans.size(); i ++) {
        for (int j = 0; j < ans[i].size(); j ++) {
            cout << ans[i][j] <<  " ";
        }
        cout << endl;
    }

    return 0;
}
