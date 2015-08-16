#include <iostream>
#include <vector>

using namespace std;

int low_bound(vector<int>& nums, int target) {
    int l, r;
    l = 0; r = nums.size();
    while(l < r) {
        int mid = (l+r)/2;
        if(nums[mid] >= target) {
            r = mid;
        }else{
            l = mid+1;
        }
    }
    return l;
}

int up_bound(vector<int>& nums, int target) {
    int l, r;
    l = 0; r = nums.size();
    while(l < r) {
        int mid = (l+r)/2;
        if(nums[mid] <= target) {
            l = mid+1;
        }else{
            r = mid;
        }
    }
    return r;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    int l = low_bound(nums, target);
    int r = up_bound(nums, target);
    if(l == r) {
        ans.push_back(-1);
        ans.push_back(-1);
    }else{
        ans.push_back(l);
        ans.push_back(r-1);
    }
    return ans;
}

int main() {
    vector<int> q;
    q.push_back(5);
    q.push_back(7);
    q.push_back(7);
    q.push_back(8);
    q.push_back(8);
    q.push_back(9);
    vector<int> p = searchRange(q, 8);
        cout << p[0] << " " << p[1] << endl;
    return 0;
}

