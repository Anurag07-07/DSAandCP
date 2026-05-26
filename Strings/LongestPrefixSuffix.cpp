//
// Created by anura on 26-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n;cin>>n;
    while (n--) {
    string s;cin>>s;

    //Create Lps Table
    int n = s.length();
    vector<int> lps(n,0);
    int pre = 0;
    int suff = 1;
    while (suff<n) {
        if (s[pre]==s[suff]) {
            lps[suff] = pre+1;
            suff++;
            pre++;
        }else {
            if (pre==0) {
                lps[suff++] = 0;
            }else {
                pre = lps[pre-1];
            }
        }
    }

    cout<<lps[lps.size()-1]<<endl;
    }
}
