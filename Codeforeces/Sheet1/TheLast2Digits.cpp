//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    long long a,b,c,d;cin>>a>>b>>c>>d;
    long long a1 = (a%100);
    long long b1 = (b%100);
    long long c1 = (c%100);
    long long d1 = (d%100);
    long long ans = (a1*b1*c1*d1)%100;
    if (ans<10) {
        cout<<"0"<<ans;
    }else {
        cout<<ans<<endl;
    }
}
