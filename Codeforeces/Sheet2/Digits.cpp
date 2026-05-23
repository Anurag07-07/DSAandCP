//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
void Print(int n) {
    while (n!=0) {
        cout<<n%10<<" ";
        n/=10;
    }

    cout<<endl;
}
int main(int argc, char *argv[]) {
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        if (n==0) cout<<0;
        Print(n);
    }
}
