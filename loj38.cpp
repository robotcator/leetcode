#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    if(n == 1) return "1";
    else{
        string prev = "1";
        string next = "";
        for (int Case = 2; Case <= n; Case ++) {
            next = "";
            int i, j, len;
            i = j = 0;
            len = prev.size();
            while(i < len) {
                j = 1;
                char tmp = prev[i];
                while(i < len && prev[i] == prev[i+1]) {
                    i ++;
                    j ++;
                }
                next += char(j+'0');
                next += tmp;
                i ++;
            }
            prev = next;
        }
        return next;
    }
}

int main() {
    cout << countAndSay(1) << endl;
    cout << countAndSay(2) << endl;
    cout << countAndSay(3) << endl;
    cout << countAndSay(4) << endl;
    cout << countAndSay(5) << endl;
    cout << countAndSay(6) << endl;

    return 0;
}
