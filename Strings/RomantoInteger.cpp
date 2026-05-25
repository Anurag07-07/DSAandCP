#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanValue(char ch) {
        if (ch == 'I') return 1;
        if (ch == 'V') return 5;
        if (ch == 'X') return 10;
        if (ch == 'L') return 50;
        if (ch == 'C') return 100;
        if (ch == 'D') return 500;
        if (ch == 'M') return 1000;

        return -1;
    }

    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n-1; ++i) {
            if (romanValue(s[i])<romanValue(s[i+1])) {
                ans-=romanValue(s[i]);
            }else {
                ans+=romanValue(s[i]);
            }
        }
        ans+=romanValue(s[n-1]);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    string s;cin>>s;
    Solution s1;
    cout<<s1.romanToInt(s);
}
