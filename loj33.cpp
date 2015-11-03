#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l, r;
    l = 0; r = nums.size();
    while (l < r) {
        int mid = (l+r)/2;
        if(nums[mid] == target) return mid;

        if(nums[l] <= nums[mid]){
            if(nums[l] <= target && target < nums[mid]) {
                r = mid;
            }else{
                l = mid+1;
            }
        }else{
            if(nums[mid] < target && target <= nums[r-1]) {
                l = mid+1;
            }else{
                r = mid;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    cout << search(v, 1) << endl;
    cout << search(v, 4) << endl;
    cout << search(v, 2) << endl;
    cout << search(v, 7) << endl;
    cout << search(v, 0) << endl;
    cout << search(v, 9) << endl;

    return 0;
}
