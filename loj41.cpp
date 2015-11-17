#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// time O(n)  space O(n)
/*
int firstMissingPositive(vector<int>& nums) {
    int len = nums.size();
    vector<int> v (len, -1);
    int i = 0;
    while(i < len) {
        if(!(nums[i] < 0 || nums[i] >= len)) {
            v[nums[i]] = 0;
        }
        i ++;
    }
    int flag = -1;
    for (int i = 0; i < len; i ++) {
        if(v[i] != 0) {
            flag = i;
        }
    }
    if(flag == -1) flag = len;
    return flag;
}
*/
// time O(n) space O(1)
//

//void swap(int& a, int& b) {
//    int tmp = a;
//    a = b;
//    b = tmp;
//}

void test(vector<int> v) {
    int len = v.size();
    for (int i = 0; i < len; i ++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// remove the duplicate elements
// the case : 1, 2, 3
// find the first positive number, 0 is not a positive number
int firstMissingPositive(vector<int>& nums) {
    nums.push_back(0);
    int len = nums.size();
    int i = 0;
    int tmp = -1;
    while(i < len) {
        if(nums[i] < 0 || nums[i] >= len) nums[i] = -1;
        else if(i == nums[i]) {

        }else {
            swap(tmp, nums[i]);
            test(nums);
            while(tmp != -1) {
                if(tmp >= len || nums[tmp] == tmp) {
                    tmp = -1;
                    break;
                }
                swap(tmp, nums[tmp]);
                test(nums);
            }
        }
        i ++;
    }
    i = 0;
    while(i < len) {
        if(i != nums[i]) break;
        i ++;
    }
    return i;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    cout << firstMissingPositive(v) << endl;

    v.clear();
    v.push_back(3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(1);
    cout << firstMissingPositive(v) << endl;

    v.clear();
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    cout << firstMissingPositive(v) << endl;

    v.clear();
    v.push_back(1);
    v.push_back(1);
    cout << firstMissingPositive(v) << endl;


    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << firstMissingPositive(v) << endl;


    v.clear();
    v.push_back(1);
    cout << firstMissingPositive(v) << endl;

    return 0;
}
