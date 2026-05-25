//
// Created by anura on 25-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int Brute(string s) {
    int n = s.length();
    int i = 0;
    int max_len = 0;
    unordered_set<int> s1;
    for (int j = 0; j < n; ++j) {

        while(s1.count(s[j])) {
            s1.erase(s[i]);
            i++;
        }

        s1.insert(s[j]);
        max_len = max(max_len,j-i+1);
    }
    return max_len;
}
int main(int argc, char *argv[]) {
    string s;cin>>s;
    cout<<Brute(s);
}
