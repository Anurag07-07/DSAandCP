//
// Created by anura on 23-05-2026.
//
//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n;cin>>n;
    for (int i = 1; i <= n; ++i) {
        //Print " "
        for (int j = 1; j <= n-i; ++j) {
            cout<<" ";
        }
        for (int j = 1;j <= i; ++j) {
            cout<<"*";
        }
        for (int j = 1;j <= i-1; ++j) {
            cout<<"*";
        }
        cout<<endl;
    }
    for (int i = 1; i <= n; ++i) {
        //Print " "
        for (int j = 1;j <= i-1; ++j) {
            cout<<" ";
        }
        for (int j = 1;j <= n-i+1; ++j) {
            cout<<"*";
        }
        for (int j = 1;j <= n-i; ++j) {
            cout<<"*";
        }
        cout<<endl;
    }
}
