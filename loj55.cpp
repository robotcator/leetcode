#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool dfs(int index, int last, vector<int> nums){
    if(index == last) {
        return true;
    }else{
        for (int j = 1; j <= nums[index]; j ++) {
            if(dfs(index+j, last, nums)) return true;
        }
    }
    return false;
}

bool canJump(vector<int>& nums) {
    // dfs will tle
    //return dfs(0, nums.size()-1, nums);
    int len = nums.size();
    int last = len-1;
    for (int i = len-2; i >= 0; i --) {
        if(last <= nums[i]+i) last = i;
        else return false;
    }
    return true;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(4);
    cout << canJump(v) << endl;

    v.clear();
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(4);
    cout << canJump(v) << endl;

    return 0;
}
