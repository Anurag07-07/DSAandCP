//
// Created by anura on 24-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    string s;cin>>s;

    vector<int> lower(26,0);
    vector<int> upper(26,0);

    for (int i = 0; i < s.length(); ++i) {
        if (s[i]>='a') {
            lower[s[i]-'a']++;
        }else {
            upper[s[i]-'A']++;
        }
    }

    //Total Count
    int count = 0;
    int odd = 0;
    for (int i = 0; i < lower.size(); ++i) {
        if (lower[i]%2==0) {
            count+=lower[i];
        }else {
            count+=(lower[i]-1);
            odd = 1;
        }
    }

    for (int i = 0; i < upper.size(); ++i) {
        if (upper[i]%2==0) {
            count+=upper[i];
        }else {
            count+=(upper[i]-1);
            odd = 1;
        }
    }

    cout<<count+odd<<endl;
}
