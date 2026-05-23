//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b) {
    if (b==0) {
        return a;
    }
    return GCD(b,a%b);
}
int main(int argc, char *argv[]) {
    int a,b;cin>>a>>b;
    cout<<GCD(a,b);
}
