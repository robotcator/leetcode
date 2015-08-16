#include <string>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int len = s.size();
    if(len <= 1) return len;
    int i, j;
    map<char, int> mp;
    i = 0; j = 1;
    mp[s[0]] = 0;
    int ans = -0x3f3f3f3f;
    while (i < len && j < len) {
        while (j < len && (mp.find(s[j]) == mp.end() || mp[s[j]] < i)) {
            mp[s[j]] = j;
            j ++;
        }
        if (j == len || mp.find(s[j]) != mp.end()) {
            if (ans < j-i) {
                ans = j-i;
            }
            i = mp[s[j]]+1;
            mp[s[j]] = j;
            j ++;
        }
    }
    return ans;
}

int main() {
    cout << lengthOfLongestSubstring("aab") << endl;
    cout << lengthOfLongestSubstring("au") << endl;
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("abccbcbb") << endl;
    cout << lengthOfLongestSubstring("bbbb") << endl;
    return 0;
}
