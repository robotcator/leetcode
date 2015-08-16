#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l, r;
    l = 0; r = nums.size();
    while(l < r) {
        int mid = (l+r)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) {
            r = mid;
        }else{
            l = mid+1;
        }
    }
    return l;
}

int main() {
    vector<int> q;
    q.push_back(1);
    q.push_back(3);
    q.push_back(5);
    q.push_back(6);
    cout << searchInsert(q, 5) << endl;
    cout << searchInsert(q, 2) << endl;
    cout << searchInsert(q, 7) << endl;
    cout << searchInsert(q, 0) << endl;
    return 0;
}
