//
// Created by anura on 24-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    string s = "1.1.1.1";
    //Output = 1[.]1[.]1[.]1
    string ans = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i]=='.') {
            ans+="[.]";
        }else {
            ans+=(s[i]);
        }
    }
    cout<<ans<<endl;
}
