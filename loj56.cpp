#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0) {};
    Interval(int s, int e) : start(s), end(e) {};
};

struct _comLess{
    bool operator() (const Interval& left, const Interval& right) {
        if(left.start == right.start)
            return left.end < right.end;
        else return left.start < right.start;
    }
}compLess;

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;
    int len = intervals.size();
    sort(intervals.begin(), intervals.end(), compLess);
    int cur = 0;
    while(cur < len) {
        int next = cur+1;
        if(next == len) {
            result.push_back(intervals[cur]);
            break;
        }
        if(intervals[cur].start == intervals[next].start) {
            cur = next;
        }else if(intervals[cur].end < intervals[next].start) {
            result.push_back(intervals[cur]);
            cur = next;
        }else if(intervals[cur].end >= intervals[next].start){
            int st = intervals[cur].start;
            int ed = max(intervals[cur].end, intervals[next].end);

            while(next < len) {
                if(intervals[next].end <= ed) next ++;
                else if(intervals[next].end > ed
                        && intervals[next].start <= ed) {
                    ed = max(ed, intervals[next].end);
                    next ++;
                }else if(intervals[next].start > ed){
                    break;
                }
            }

            cout << next << " len " << len << endl;
            result.push_back(Interval(st, ed));
            cur = next;

        }
    }
    return result;
}

int main() {
    vector<Interval> v;
    v.push_back(Interval(1, 3));
    v.push_back(Interval(1, 2));
    v.push_back(Interval(2, 8));
    v.push_back(Interval(8, 10));
    v.push_back(Interval(15, 18));

    vector<Interval> ans = merge(v);

    for (int i = 0; i < (int)ans.size(); i ++) {
        cout << ans[i].start << " " << ans[i].end << endl;
    }

    return 0;
}
