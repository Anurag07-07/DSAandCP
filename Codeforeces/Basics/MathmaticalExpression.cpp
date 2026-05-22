//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int a;cin>>a;
    char s;cin>>s;
    int b;cin>>b;
    char q;cin>>q;
    int c;cin>>c;

    if (s=='+') {
        if (a+b==c) {
            cout<<"Yes";
        }else {
            cout<<a+b;
        }
    } else if (s=='*') {
        if (a*b==c) {
            cout<<"Yes";
        }else {
            cout<<a*b;
        }
    } if (s=='-') {
        if (a-b==c) {
            cout<<"Yes";
        }else {
            cout<<a-b;
        }
    }
}
