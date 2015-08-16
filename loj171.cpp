#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution{
public:
    int titleToNumber(string s) {
        int len = s.size();
        int ans = 0;
        for (int i = 0; i < len; i ++) {
            ans = ans*26 + (s[i]-'A'+1);
        }
        return ans;
    }
};

int main() {
    Solution *solu = new Solution();
    cout << solu->titleToNumber("AA") << endl;
    cout << solu->titleToNumber("AB") << endl;
    return 0;
}
