#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    if(len == 0) return 0;
    vector<int> dp (len, 0);
    dp[0] = nums[0];
    for (int i = 1; i < len; i ++) {
        if(dp[i-1] + nums[i] > nums[i]) {
            dp[i] = dp[i-1] + nums[i];
        }else{
            dp[i] = nums[i];
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    return 0;
}
