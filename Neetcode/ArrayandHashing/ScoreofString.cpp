//
// Created by anura on 11-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;

        for (int i = 0; i < s.length()-1; ++i) {
            //Find the Character Code
            char c1 = s[i];
            char c2 = s[i+1];
            int code = abs(c1-c2);
            score+=code;
        }
        return score;
    }
};

int main(int argc, char *argv[]) {
    string s;cin>>s;
    Solution s1;
    cout<<s1.scoreOfString(s);
}
