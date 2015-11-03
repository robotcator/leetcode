#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// naive algorithm
int threeSumClosest(vector<int>& nums, int target) {
    int len = nums.size();

    if(len < 3) return 0;

    sort(nums.begin(), nums.end());

    int closetSum = 0x3f3f3f3f;

    for (int i = 0; i < len; i ++) {
        int st = i+1, ed = len-1;
        while(st < ed) {
            int sum = nums[i] + nums[st] + nums[ed];

            cout << st << " " << ed << " " << sum << endl;

            if(sum == target) return sum;

            if(abs(sum-target) < abs(closetSum-target)) {
                closetSum = sum;
            }
            if(sum < target) {
                st ++;
                while(st < ed && nums[st-1] == nums[st]) st++;
            }else {
                ed --;
                while(st < ed && nums[ed+1] == nums[ed]) ed --;
            }
        }
        while(i+1 < len && nums[i] == nums[i+1]) i ++;
    }
    return closetSum;
}

int main() {
    vector<int> v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);

    int ans = threeSumClosest(v, 1);

    cout << ans << endl;

    return 0;
}

