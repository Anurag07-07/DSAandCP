//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int a;cin>>a;
    char s;cin>>s;
    int b;cin>>b;
    if (s=='+') {
        cout<<a+b;
    }else if (s=='-') {
        cout<<a-b;
    }else if (s=='*') {
        cout<<a*b;
    }else {
        cout<<a/b;
    }
}
