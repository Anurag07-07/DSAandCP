//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

void LowertoUpper(string &s,int start,int end) {
    //Base Case
    if (start>end) {
        return;
    }

    //Convert into Lower Case
    if (s[start]>='a' && s[start]<='z') {
        s[start] = 'A'+(s[start]-'a');
    }

    LowertoUpper(s,start+1,end);
}

int main(int argc, char *argv[]) {
    string s = "AnurAG";
    LowertoUpper(s,0,s.length()-1);
    cout<<s;
}
