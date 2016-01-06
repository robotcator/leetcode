#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
// wrong case
// 2 1 0 2
int trap(vector<int>& height) {
    stack<int> s;
    int len = height.size();
    int ans = 0;
    s.push(0);
    for (int i = 1; i < len; i ++) {
        int last = s.top();
        int minH = height[i];
        while(!s.empty() && height[s.top()] < height[i]) {
            cout << " flag " << s.top() << endl;
            last = s.top();
            if(height[last] < minH) minH = height[last];
            s.pop();
        }
        cout << i << " " << last << " " << minH << endl;
        if(s.empty()) {
            ans += (i-last-1) * (min(height[last], height[i])-minH);
        }else{
            ans += (i-s.top()-1) * (min(height[s.top()], height[i])-minH);
        }
        cout << " ans " << ans << endl;
        s.push(i);
    }
    cout << ans << endl;
    return ans;
}
*/

int trap(vector<int>& height) {
    stack<int> s;
    int len = height.size();
    int ans = 0;
    s.push(0);
    for (int i = 1; i < len; i ++) {
        int last = s.top();
        int minH = height[i];
        while(!s.empty() && height[s.top()] <= height[i]) {
            cout << " flag " << s.top() << endl;
            last = s.top();
            if(height[last] < minH) minH = height[last];
            s.pop();
            if(!s.empty()){
                int H = min(height[i], height[s.top()]) - height[last];
                ans += H * (i-s.top()-1);
                cout << ans << endl;
            }
        }
        s.push(i);
        cout << ans << " " << s.size() << endl;
    }
    cout << "ans " << ans << endl;
    return ans;
}


int main() {
    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);

    cout << trap(v) << endl;

    v.clear();
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);

    cout << trap(v) << endl;

    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);

    cout << trap(v) << endl;

    return 0;
}
