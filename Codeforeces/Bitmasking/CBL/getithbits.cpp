//
// Created by anura on 27-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

int getith(int n,int i) {
    int mask = 1<<i;
    int ans = n&mask;
    return ans > 0 ? 1 : 0;
}

int setbit(int n ,int pos) {
    int mask = 1<<pos;
    int ans = n | mask;
    return ans;
}

int clearbit(int n,int i) {
    int mask = ~(1<<i);
    int ans = n & mask;
    return  ans;
}

int main(int argc, char *argv[]) {
    int n,i;cin>>n>>i;

    // cout<<getith(n,i)<<endl;
    // cout<<setbit(n,i)<<endl;
    cout<<clearbit(n,i)<<endl;
}
