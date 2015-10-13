#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int maxArea(vector<int>& height) {
    int i, j, maxA;
    i = 0, j = height.size()-1, maxA = 0;
    while(i < j) {
        maxA = max(maxA, (j-i)*min(height[j], height[i]));
        if(height[i] < height[j]) {
            int tmp = height[i++];
            while(i < j && height[i] < tmp) i ++;
        }else{
            int tmp = height[j--];
            while(i < j && height[j] < tmp) j --;
        }
    }
    return maxA;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);

    cout << maxArea(v) << endl;

    return 0;
}
