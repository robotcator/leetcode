#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int start, end, m, sum, len;
    start = end = sum = 0;
    m = nums.size()+1;
    len = nums.size();
    while(start < len && end < len) {
        while(end < len && sum < s) {
            sum += nums[end];
            end ++;
        }
        while(start < len && sum >= s) {
            m = m > (end-start) ? end-start : m;
            sum -= nums[start];
            start ++;
        }
    }
    return m == len+1 ? 0 : m;
}

int main() {
    vector<int> q;
    q.push_back(2);
    q.push_back(3);
    q.push_back(1);
    q.push_back(2);
    q.push_back(4);
    q.push_back(3);
    cout << minSubArrayLen(50, q) << endl;
    return 0;
}
