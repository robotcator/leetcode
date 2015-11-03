#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int len = nums.size();
    int i = 0;
    while(i < len) {
        if(nums[i] < 0)
        while(i != nums[i]){
            swap(nums[i], nums[nums[i]]);
        }
        i ++;
    }

}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    firstMissingPositive(v);
    return 0;
}
